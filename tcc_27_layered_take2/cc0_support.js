/*
 * SpiderMonkey implementations of the operator-free cc0 primitives.
 * Arithmetic results are coerced to the signed 32-bit cc0 value model.
 */
function add(left, right) { return (left + right) | 0; }
function sub(left, right) { return (left - right) | 0; }
function eq(left, right) { return left === right ? 1 : 0; }
function lt(left, right) { return left < right ? 1 : 0; }
function le(left, right) { return left <= right ? 1 : 0; }
function not(value) { return value ? 0 : 1; }
function and(left, right) { return (left & right) | 0; }
function shl(value, count) { return (value << count) | 0; }
function ushr(value, count) { return (value >>> count) | 0; }

/* Integer addresses remain stable when the backing typed array grows. */
var CC0_SUPPORT_MEMORY_SIZE = 4096;
var cc0_support_memory = new Uint8Array(CC0_SUPPORT_MEMORY_SIZE);
var cc0_support_heap_top = 4;
var cc0_support_string_cache = {};

function cc0_support_reserve(needed) {
    var grown = CC0_SUPPORT_MEMORY_SIZE;
    var memory;
    while (grown < needed) {
        grown = grown * 2;
    }
    if (grown !== CC0_SUPPORT_MEMORY_SIZE) {
        memory = new Uint8Array(grown);
        memory.set(cc0_support_memory);
        cc0_support_memory = memory;
        CC0_SUPPORT_MEMORY_SIZE = grown;
    }
}

function alloc(size) {
    var pointer = cc0_support_heap_top;
    cc0_support_heap_top = (pointer + size + 3) & -4;
    cc0_support_reserve(cc0_support_heap_top);
    return pointer;
}

function mks(value) {
    var index;
    var pointer;
    if (Object.prototype.hasOwnProperty.call(cc0_support_string_cache, value)) {
        return cc0_support_string_cache[value];
    }
    pointer = alloc(value.length + 1);
    index = 0;
    while (index < value.length) {
        cc0_support_memory[pointer + index] = value.charCodeAt(index) & 255;
        index = index + 1;
    }
    cc0_support_memory[pointer + index] = 0;
    cc0_support_string_cache[value] = pointer;
    return pointer;
}

function ri8(address) {
    return cc0_support_memory[address] | 0;
}

function wi8(address, value) {
    cc0_support_memory[address] = value & 255;
    return value | 0;
}

function ri32(address) {
    return (cc0_support_memory[address] |
            (cc0_support_memory[address + 1] << 8) |
            (cc0_support_memory[address + 2] << 16) |
            (cc0_support_memory[address + 3] << 24)) | 0;
}

function wi32(address, value) {
    cc0_support_memory[address] = value & 255;
    cc0_support_memory[address + 1] = (value >>> 8) & 255;
    cc0_support_memory[address + 2] = (value >>> 16) & 255;
    cc0_support_memory[address + 3] = (value >>> 24) & 255;
    return value | 0;
}

var cc0_support_files = {};
var cc0_support_next_file = 3;

function cc0_support_path(address) {
    var value = "";
    while (ri8(address) !== 0) {
        value = value + String.fromCharCode(ri8(address));
        address = address + 1;
    }
    return value;
}

function file_open_read(path) {
    var descriptor = cc0_support_next_file++;
    cc0_support_files[descriptor] = {
        data: os.file.readFile(cc0_support_path(path)),
        position: 0,
        output: false
    };
    return descriptor;
}

function file_open_write(path) {
    var descriptor = cc0_support_next_file++;
    cc0_support_files[descriptor] = {
        data: [],
        path: cc0_support_path(path),
        position: 0,
        output: true
    };
    return descriptor;
}

function file_size(descriptor) {
    return cc0_support_files[descriptor].data.length | 0;
}

function file_read_byte(descriptor) {
    var file = cc0_support_files[descriptor];
    if (file.position >= file.data.length) {
        return -1;
    }
    return file.data.charCodeAt(file.position++) & 255;
}

function file_write_byte(descriptor, value) {
    cc0_support_files[descriptor].data.push(value & 255);
    return 1;
}

function file_close(descriptor) {
    var file = cc0_support_files[descriptor];
    if (file.output) {
        os.file.writeTypedArrayToFile(file.path, new Uint8Array(file.data));
    }
    delete cc0_support_files[descriptor];
    return 0;
}

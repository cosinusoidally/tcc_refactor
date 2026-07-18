/* SpiderMonkey meanings for operations outside the operator-free dialect. */
function add(left, right) { return (left + right) | 0; }
function sub(left, right) { return (left - right) | 0; }
function mul(left, right) { return Math.imul(left, right) | 0; }
function sdiv(left, right) { return (left / right) | 0; }
function mod(left, right) { return (left % right) | 0; }
function eq(left, right) { return (left | 0) === (right | 0) ? 1 : 0; }
function lt(left, right) { return (left | 0) < (right | 0) ? 1 : 0; }
function le(left, right) { return (left | 0) <= (right | 0) ? 1 : 0; }
function not(value) { return value ? 0 : 1; }
function and(left, right) { return (left & right) | 0; }
function or(left, right) { return (left | right) | 0; }
function xor(left, right) { return (left ^ right) | 0; }
function bnot(value) { return (~value) | 0; }
function shl(value, count) { return (value << count) | 0; }
function shr(value, count) { return (value >> count) | 0; }
function ushr(value, count) { return (value >>> count) | 0; }

/* Integer addresses remain stable when the backing typed array grows. */
var CC0_PRIMS_MEMORY_SIZE = 4096;
var cc0_prims_memory = new Uint8Array(CC0_PRIMS_MEMORY_SIZE);
var cc0_prims_string_cache = {};

function cc0_prims_reserve(needed) {
    var grown = CC0_PRIMS_MEMORY_SIZE;
    var memory;
    while (grown < needed) {
        grown = grown * 2;
    }
    if (grown !== CC0_PRIMS_MEMORY_SIZE) {
        memory = new Uint8Array(grown);
        memory.set(cc0_prims_memory);
        cc0_prims_memory = memory;
        CC0_PRIMS_MEMORY_SIZE = grown;
    }
}

function mks(value) {
    var index;
    var pointer;
    if (Object.prototype.hasOwnProperty.call(cc0_prims_string_cache, value)) {
        return cc0_prims_string_cache[value];
    }
    pointer = malloc(value.length + 1);
    index = 0;
    while (index < value.length) {
        cc0_prims_memory[pointer + index] = value.charCodeAt(index) & 255;
        index = index + 1;
    }
    cc0_prims_memory[pointer + index] = 0;
    cc0_prims_string_cache[value] = pointer;
    return pointer;
}

function mkC(value) {
    return value.charCodeAt(0) | 0;
}

function ri8(address) {
    return cc0_prims_memory[address] | 0;
}

function wi8(address, value) {
    cc0_prims_memory[address] = value & 255;
    return value | 0;
}

function ri32(address) {
    return (cc0_prims_memory[address] |
            (cc0_prims_memory[address + 1] << 8) |
            (cc0_prims_memory[address + 2] << 16) |
            (cc0_prims_memory[address + 3] << 24)) | 0;
}

function wi32(address, value) {
    cc0_prims_memory[address] = value & 255;
    cc0_prims_memory[address + 1] = (value >>> 8) & 255;
    cc0_prims_memory[address + 2] = (value >>> 16) & 255;
    cc0_prims_memory[address + 3] = (value >>> 24) & 255;
    return value | 0;
}

/* The shared libc is layered over these irreducible host operations. */
var cc0_prims_files = {};
var cc0_prims_next_file = 3;
/* Keep address zero null and leave one word before the first allocation. */
var cc0_prims_break = 4;

function cc0_prims_path(address) {
    var value = "";
    while (ri8(address) !== 0) {
        value = value + String.fromCharCode(ri8(address));
        address = address + 1;
    }
    return value;
}

function cc0_runtime_open(path, flags, mode) {
    var descriptor = cc0_prims_next_file++;
    var access = flags & 3;
    var writing = access !== 0;
    var truncate = (flags & 512) !== 0;
    var append = (flags & 1024) !== 0;
    var data;
    if (truncate) {
        data = [];
    } else {
        try {
            data = os.file.readFile(cc0_prims_path(path), "binary");
        } catch (error) {
            if (!writing || (flags & 64) === 0) {
                return -1;
            }
            data = [];
        }
    }
    cc0_prims_files[descriptor] = {
        data: data,
        path: cc0_prims_path(path),
        position: append ? data.length : 0,
        output: writing
    };
    return descriptor;
}

function cc0_runtime_lseek(descriptor, offset, origin) {
    var file = cc0_prims_files[descriptor];
    if (origin === 2) {
        file.position = file.data.length;
    } else if (origin === 0) {
        file.position = offset;
    } else if (origin === 1) {
        file.position += offset;
    }
    return file.position | 0;
}

function cc0_runtime_read(descriptor, buffer, count) {
    var file = cc0_prims_files[descriptor];
    var index = 0;
    while (index < count && file.position < file.data.length) {
        wi8(buffer + index, file.data[file.position]);
        file.position++;
        index++;
    }
    return index | 0;
}

function cc0_runtime_write(descriptor, buffer, count) {
    var index = 0;
    var text = "";
    var file;
    if (descriptor === 1 || descriptor === 2) {
        while (index < count) {
            text += String.fromCharCode(ri8(buffer + index));
            index++;
        }
        putstr(text);
        return count | 0;
    }
    file = cc0_prims_files[descriptor];
    index = 0;
    while (index < count) {
        file.data[file.position] = ri8(buffer + index);
        file.position++;
        index++;
    }
    return count | 0;
}

function cc0_runtime_close(descriptor) {
    var file = cc0_prims_files[descriptor];
    if (file.output) {
        os.file.writeTypedArrayToFile(file.path, new Uint8Array(file.data));
    }
    delete cc0_prims_files[descriptor];
    return 0;
}

function cc0_runtime_brk(address) {
    if (address === 0) {
        return cc0_prims_break;
    }
    cc0_prims_reserve(address);
    cc0_prims_break = address;
    return address;
}

function cc0_runtime_exit(status) {
    quit(status);
}

function chmod(path, mode) {
    return os.system("chmod 755 '" + cc0_prims_path(path) + "'");
}

/* Seed execution must never delete host files. */
function cc0_runtime_unlink(path) {
    return 0;
}

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
var cc0_prims_heap_top = 4;
var cc0_prims_allocation_sizes = {};
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

function malloc(size) {
    var pointer = cc0_prims_heap_top;
    if (size === 0) {
        size = 1;
    }
    cc0_prims_heap_top = (pointer + size + 3) & -4;
    cc0_prims_reserve(cc0_prims_heap_top);
    cc0_prims_allocation_sizes[pointer] = size;
    return pointer;
}

function realloc(pointer, size) {
    var replacement = malloc(size);
    var oldSize = cc0_prims_allocation_sizes[pointer] | 0;
    var copySize = oldSize < size ? oldSize : size;
    var index = 0;
    while (index < copySize) {
        cc0_prims_memory[replacement + index] =
            cc0_prims_memory[pointer + index];
        index++;
    }
    return replacement;
}

/* JavaScript owns allocations, so release needs no explicit heap operation. */
function free(pointer) {
    return 0;
}

function calloc(count, size) {
    var bytes = Math.imul(count, size) | 0;
    var pointer = malloc(bytes);
    var index = 0;
    while (index < bytes) {
        wi8(pointer + index, 0);
        index++;
    }
    return pointer;
}

function memset(destination, value, size) {
    var index = 0;
    while (index < size) {
        wi8(destination + index, value);
        index++;
    }
    return destination;
}

function memcpy(destination, source, size) {
    var index = 0;
    while (index < size) {
        wi8(destination + index, ri8(source + index));
        index++;
    }
    return destination;
}

function memmove(destination, source, size) {
    var index;
    if (destination <= source) {
        return memcpy(destination, source, size);
    }
    index = size;
    while (index > 0) {
        index--;
        wi8(destination + index, ri8(source + index));
    }
    return destination;
}

function memcmp(left, right, size) {
    var index = 0;
    while (index < size && ri8(left + index) === ri8(right + index)) {
        index++;
    }
    if (index === size) {
        return 0;
    }
    return (ri8(left + index) - ri8(right + index)) | 0;
}

function strlen(text) {
    var length = 0;
    while (ri8(text + length) !== 0) {
        length++;
    }
    return length;
}

function strcpy(destination, source) {
    var index = 0;
    do {
        wi8(destination + index, ri8(source + index));
        index++;
    } while (ri8(source + index - 1) !== 0);
    return destination;
}

function strcat(destination, source) {
    strcpy(destination + strlen(destination), source);
    return destination;
}

function strcmp(left, right) {
    var index = 0;
    while (ri8(left + index) === ri8(right + index) &&
           ri8(left + index) !== 0) {
        index++;
    }
    return (ri8(left + index) - ri8(right + index)) | 0;
}

function strncmp(left, right, count) {
    var index = 0;
    while (index < count && ri8(left + index) === ri8(right + index) &&
           ri8(left + index) !== 0) {
        index++;
    }
    if (index === count) {
        return 0;
    }
    return (ri8(left + index) - ri8(right + index)) | 0;
}

function strchr(text, character) {
    while (ri8(text) !== character) {
        if (ri8(text) === 0) {
            return 0;
        }
        text++;
    }
    return text;
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

/* These functions model the small libc surface used by cc1.c. */
var cc0_prims_files = {};
var cc0_prims_next_file = 3;

function cc0_prims_path(address) {
    var value = "";
    while (ri8(address) !== 0) {
        value = value + String.fromCharCode(ri8(address));
        address = address + 1;
    }
    return value;
}

function open(path, flags, mode) {
    var descriptor = cc0_prims_next_file++;
    var writing = (flags & 1) !== 0;
    var data;
    if (writing) {
        data = [];
    } else {
        try {
            data = os.file.readFile(cc0_prims_path(path), "binary");
        } catch (error) {
            return -1;
        }
    }
    cc0_prims_files[descriptor] = {
        data: data,
        path: cc0_prims_path(path),
        position: 0,
        output: writing
    };
    return descriptor;
}

function lseek(descriptor, offset, origin) {
    var file = cc0_prims_files[descriptor];
    if (origin === 2) {
        file.position = file.data.length;
    } else if (origin === 0) {
        file.position = offset;
    }
    return file.position | 0;
}

function read(descriptor, buffer, count) {
    var file = cc0_prims_files[descriptor];
    var index = 0;
    while (index < count && file.position < file.data.length) {
        wi8(buffer + index, file.data[file.position]);
        file.position++;
        index++;
    }
    return index | 0;
}

function write(descriptor, buffer, count) {
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
        file.data.push(ri8(buffer + index));
        index++;
    }
    return count | 0;
}

function puts(text) {
    putstr(cc0_prims_path(text) + "\n");
    return 0;
}

function close(descriptor) {
    var file = cc0_prims_files[descriptor];
    if (file.output) {
        os.file.writeTypedArrayToFile(file.path, new Uint8Array(file.data));
    }
    delete cc0_prims_files[descriptor];
    return 0;
}

/* The seed represents FILE handles with the existing descriptor integers. */
function fopen(path, mode) {
    var modeText = cc0_prims_path(mode);
    var flags = modeText.charAt(0) === "r" ? 0 : 577;
    return open(path, flags, 384);
}

function fwrite(buffer, size, count, stream) {
    var bytes = write(stream, buffer, Math.imul(size, count));
    return size === 0 ? 0 : (bytes / size) | 0;
}

function fputc(character, stream) {
    var buffer = malloc(1);
    wi8(buffer, character);
    return write(stream, buffer, 1) === 1 ? character : -1;
}

function fclose(stream) {
    return close(stream);
}

function chmod(path, mode) {
    return os.system("chmod 755 '" + cc0_prims_path(path) + "'");
}

/* Seed execution must never delete host files. */
function unlink(path) {
    return 0;
}

/* The reproducible seed ignores host compiler search-path environment data. */
function getenv(name) {
    return 0;
}

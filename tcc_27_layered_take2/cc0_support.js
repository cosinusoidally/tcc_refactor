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

/* This byte array models the flat address space used by cc0 host tests. */
var CC0_SUPPORT_MEMORY_SIZE = 1048576;
var cc0_support_memory = new Uint8Array(CC0_SUPPORT_MEMORY_SIZE);
var cc0_support_heap_top = 4096;
var cc0_support_string_top = 524288;
var cc0_support_string_cache = {};

function alloc(size) {
    var pointer = cc0_support_heap_top;
    cc0_support_heap_top = (pointer + size + 3) & -4;
    return pointer;
}

function mks(value) {
    var index;
    var pointer;
    if (Object.prototype.hasOwnProperty.call(cc0_support_string_cache, value)) {
        return cc0_support_string_cache[value];
    }
    pointer = cc0_support_string_top;
    index = 0;
    while (index < value.length) {
        cc0_support_memory[pointer + index] = value.charCodeAt(index) & 255;
        index = index + 1;
    }
    cc0_support_memory[pointer + index] = 0;
    cc0_support_string_top = pointer + index + 1;
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

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
var CC0_SUPPORT_MEMORY_SIZE = 65536;
var cc0_support_memory = new Uint8Array(CC0_SUPPORT_MEMORY_SIZE);

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

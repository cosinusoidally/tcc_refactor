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

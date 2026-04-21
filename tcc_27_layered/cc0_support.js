/*
 * JavaScript runtime support for cc0 wrapper literals.
 */

var cc0_heap;
var cc0_heap_next;

cc0_heap = [];
cc0_heap_next = 1;

function mkc(c)
{
    if (typeof c == "number")
        return c;
    return c.charCodeAt(0);
}

function mks(s)
{
    var base;
    var i;

    base = cc0_heap_next;
    i = 0;
    while (i < s.length) {
        cc0_heap[base + i] = s.charCodeAt(i);
        i = i + 1;
    }
    cc0_heap[base + i] = 0;
    cc0_heap_next = base + i + 1;
    return base;
}

function cc0_heap_get(ptr, offset)
{
    return cc0_heap[ptr + offset];
}

function cc0_heap_slice(ptr, start, len)
{
    var base;
    var i;

    base = cc0_heap_next;
    i = 0;
    while (i < len) {
        cc0_heap[base + i] = cc0_heap[ptr + start + i];
        i = i + 1;
    }
    cc0_heap[base + i] = 0;
    cc0_heap_next = base + i + 1;
    return base;
}

function cc0_heap_is_string(ptr, c0, c1, c2, c3)
{
    if (cc0_heap_get(ptr, 0) != c0)
        return 0;
    if (cc0_heap_get(ptr, 1) != c1)
        return 0;
    if (cc0_heap_get(ptr, 2) != c2)
        return 0;
    if (cc0_heap_get(ptr, 3) != c3)
        return 0;
    return 1;
}

function cc0_cell_alloc(count)
{
    var base;

    base = cc0_heap_next;
    cc0_heap_next = cc0_heap_next + count;
    return base;
}

function cc0_cell_get(ptr, index)
{
    return cc0_heap[ptr + index];
}

function cc0_cell_set(ptr, index, value)
{
    cc0_heap[ptr + index] = value;
    return value;
}

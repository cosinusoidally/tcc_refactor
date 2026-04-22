typedef int Wtype;
typedef unsigned int UWtype;
typedef unsigned int USItype;
typedef long long DWtype;
typedef unsigned long long UDWtype;
struct DWstruct {
    Wtype low, high;
};
typedef union
{
  struct DWstruct s;
  DWtype ll;
} DWunion;
static UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
    UDWtype q = 0;
    if (d == 0)
        d = 1 / (UWtype)d;
    while (n >= d) {
        n -= d;
        q++;
    }
    if (rp)
        *rp = n;
    return q;
}
long long __divdi3(long long u, long long v)
{
    int c = 0;
    DWunion uu, vv;
    DWtype w;
    uu.ll = u;
    vv.ll = v;
    if (uu.s.high < 0) {
        c = ~c;
        uu.ll = (-(uu.ll));
    }
    if (vv.s.high < 0) {
        c = ~c;
        vv.ll = (-(vv.ll));
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    if (c)
        w = (-(w));
    return w;
}
long long __moddi3(long long u, long long v)
{
    int c = 0;
    DWunion uu, vv;
    DWtype w;
    uu.ll = u;
    vv.ll = v;
    if (uu.s.high < 0) {
        c = ~c;
        uu.ll = (-(uu.ll));
    }
    if (vv.s.high < 0)
        vv.ll = (-(vv.ll));
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    if (c)
        w = (-(w));
    return w;
}
unsigned long long __udivdi3(unsigned long long u, unsigned long long v)
{
    return __udivmoddi4 (u, v, (UDWtype *) 0);
}
unsigned long long __umoddi3(unsigned long long u, unsigned long long v)
{
    UDWtype w;
    __udivmoddi4 (u, v, &w);
    return w;
}
long long __ashrdi3(long long a, int b)
{
    DWunion u;
    u.ll = a;
    if (b >= 32) {
        u.s.low = u.s.high >> (b - 32);
        u.s.high = u.s.high >> 31;
    } else if (b != 0) {
        u.s.low = ((unsigned)u.s.low >> b) | (u.s.high << (32 - b));
        u.s.high = u.s.high >> b;
    }
    return u.ll;
}
unsigned long long __lshrdi3(unsigned long long a, int b)
{
    DWunion u;
    u.ll = a;
    if (b >= 32) {
        u.s.low = (unsigned)u.s.high >> (b - 32);
        u.s.high = 0;
    } else if (b != 0) {
        u.s.low = ((unsigned)u.s.low >> b) | (u.s.high << (32 - b));
        u.s.high = (unsigned)u.s.high >> b;
    }
    return u.ll;
}
long long __ashldi3(long long a, int b)
{
    DWunion u;
    u.ll = a;
    if (b >= 32) {
        u.s.high = (unsigned)u.s.low << (b - 32);
        u.s.low = 0;
    } else if (b != 0) {
        u.s.high = ((unsigned)u.s.high << b) | ((unsigned)u.s.low >> (32 - b));
        u.s.low = (unsigned)u.s.low << b;
    }
    return u.ll;
}

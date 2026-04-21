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
typedef long double XFtype;
union ldouble_long {
    long double ld;
    struct {
        unsigned long long lower;
        unsigned short upper;
    } l;
};
union double_long {
    double d;
    struct {
        unsigned int lower;
        int upper;
    } l;
    long long ll;
};
union float_long {
    float f;
    unsigned int l;
};
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
float __floatundisf(unsigned long long a)
{
    DWunion uu;
    XFtype r;
    uu.ll = a;
    if (uu.s.high >= 0) {
        return (float)uu.ll;
    } else {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        return (float)r;
    }
}
double __floatundidf(unsigned long long a)
{
    DWunion uu;
    XFtype r;
    uu.ll = a;
    if (uu.s.high >= 0) {
        return (double)uu.ll;
    } else {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        return (double)r;
    }
}
long double __floatundixf(unsigned long long a)
{
    DWunion uu;
    XFtype r;
    uu.ll = a;
    if (uu.s.high >= 0) {
        return (long double)uu.ll;
    } else {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        return (long double)r;
    }
}
unsigned long long __fixunssfdi (float a1)
{
    register union float_long fl1;
    register int exp;
    register unsigned long l;
    fl1.f = a1;
    if (fl1.l == 0)
	return (0);
    exp = (((fl1.l) >> 23) & 0xFF) - 126 - 24;
    l = (((fl1.l) & 0x7FFFFF) | (1 << 23));
    if (exp >= 41)
	return (unsigned long long)-1;
    else if (exp >= 0)
        return (unsigned long long)l << exp;
    else if (exp >= -23)
        return l >> -exp;
    else
        return 0;
}
long long __fixsfdi (float a1)
{
    long long ret; int s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    return s ? ret : -ret;
}
unsigned long long __fixunsdfdi (double a1)
{
    register union double_long dl1;
    register int exp;
    register unsigned long long l;
    dl1.d = a1;
    if (dl1.ll == 0)
	return (0);
    exp = (((dl1.l.upper) >> 20) & 0x7FF) - 1022 - 53;
    l = ((dl1.ll & (((long long)1 << 52)-1)) | ((long long)1 << 52));
    if (exp >= 12)
	return (unsigned long long)-1;
    else if (exp >= 0)
        return l << exp;
    else if (exp >= -52)
        return l >> -exp;
    else
        return 0;
}
long long __fixdfdi (double a1)
{
    long long ret; int s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    return s ? ret : -ret;
}
unsigned long long __fixunsxfdi (long double a1)
{
    register union ldouble_long dl1;
    register int exp;
    register unsigned long long l;
    dl1.ld = a1;
    if (dl1.l.lower == 0 && dl1.l.upper == 0)
	return (0);
    exp = (dl1.l.upper & 0x7fff) - 16382 - 64;
    l = dl1.l.lower;
    if (exp > 0)
	return (unsigned long long)-1;
    else if (exp >= -63)
        return l >> -exp;
    else
        return 0;
}
long long __fixxfdi (long double a1)
{
    long long ret; int s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    return s ? ret : -ret;
}

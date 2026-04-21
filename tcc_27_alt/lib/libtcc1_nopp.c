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
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;
  nn.ll = n;
  dd.ll = d;
  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;
  if (d1 == 0)
    {
      if (d0 > n1)
	{
	  __asm__ ("divl %4"	: "=a" ((USItype) (q0)),	"=d" ((USItype) (n0))	: "0" ((USItype) (n0)),	"1" ((USItype) (n1)),	"rm" ((USItype) (d0)));
	  q1 = 0;
	}
      else
	{
	  if (d0 == 0)
	    d0 = 1 / d0;
	  __asm__ ("divl %4"	: "=a" ((USItype) (q1)),	"=d" ((USItype) (n1))	: "0" ((USItype) (n1)),	"1" ((USItype) (0)),	"rm" ((USItype) (d0)));
	  __asm__ ("divl %4"	: "=a" ((USItype) (q0)),	"=d" ((USItype) (n0))	: "0" ((USItype) (n0)),	"1" ((USItype) (n1)),	"rm" ((USItype) (d0)));
	}
      if (rp != 0)
	{
	  rr.s.low = n0;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }
  else
    {
      if (d1 > n1)
	{
	  q0 = 0;
	  q1 = 0;
	  if (rp != 0)
	    {
	      rr.s.low = n0;
	      rr.s.high = n1;
	      *rp = rr.ll;
	    }
	}
      else
	{
	  do {	USItype __cbtmp;	__asm__ ("bsrl %1,%0"	: "=r" (__cbtmp) : "rm" ((USItype) (d1)));	(bm) = __cbtmp ^ 31;	} while (0);
	  if (bm == 0)
	    {
	      if (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  __asm__ ("subl %5,%1\n\tsbbl %3,%0"	: "=r" ((USItype) (n1)),	"=&r" ((USItype) (n0))	: "0" ((USItype) (n1)),	"g" ((USItype) (d1)),	"1" ((USItype) (n0)),	"g" ((USItype) (d0)));
		}
	      else
		q0 = 0;
	      q1 = 0;
	      if (rp != 0)
		{
		  rr.s.low = n0;
		  rr.s.high = n1;
		  *rp = rr.ll;
		}
	    }
	  else
	    {
	      UWtype m1, m0;
	      b = 32 - bm;
	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;
	      __asm__ ("divl %4"	: "=a" ((USItype) (q0)),	"=d" ((USItype) (n1))	: "0" ((USItype) (n1)),	"1" ((USItype) (n2)),	"rm" ((USItype) (d1)));
	      __asm__ ("mull %3"	: "=a" ((USItype) (m0)),	"=d" ((USItype) (m1))	: "%0" ((USItype) (q0)),	"rm" ((USItype) (d0)));
	      if (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  __asm__ ("subl %5,%1\n\tsbbl %3,%0"	: "=r" ((USItype) (m1)),	"=&r" ((USItype) (m0))	: "0" ((USItype) (m1)),	"g" ((USItype) (d1)),	"1" ((USItype) (m0)),	"g" ((USItype) (d0)));
		}
	      q1 = 0;
	      if (rp != 0)
		{
		  __asm__ ("subl %5,%1\n\tsbbl %3,%0"	: "=r" ((USItype) (n1)),	"=&r" ((USItype) (n0))	: "0" ((USItype) (n1)),	"g" ((USItype) (m1)),	"1" ((USItype) (n0)),	"g" ((USItype) (m0)));
		  rr.s.low = (n1 << b) | (n0 >> bm);
		  rr.s.high = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }
  ww.s.low = q0;
  ww.s.high = q1;
  return ww.ll;
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

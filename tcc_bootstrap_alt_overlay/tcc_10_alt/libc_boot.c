extern int stdout;

int strcpy(int d, int s);
int strcat(int de,int s);

int puts(int x) {
  fputs(x, stdout);
  fputs("\n", stdout);
}

/* adapted from bootstrappable_load.c */
char* int2str(int x, int base, int signed_p)
{
        /* Be overly conservative and save space for 32binary digits and padding null */
        char* p = (char *)calloc(34, sizeof(char));
        /* if calloc fails return null to let calling code deal with it */
        if(0 == p) return p;

        p = p + 32;
        unsigned i;
        int sign_p = 0;
        char* table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if(signed_p && (10 == base) && (x < 0))
        {
                i = 0 - (unsigned)x;
                if(i == 0x80000000) return "-2147483648";
                sign_p = 1;
        }
        else i = (unsigned)x;

        do
        {
                p[0] = table[i % base];
                p = p - 1;
                i = i / base;
        } while(0 < i);

        if(sign_p)
        {
                p[0] = '-';
                p = p - 1;
        }

        return p + 1;
}

/* FIXME dummy impl */
double strtod(char *a, char **p){
  double v;
  int *x;
  x=&v;
  x[0]=0;
  x[1]=0;
  puts("tcc strtod");
  if(strcmp("4294967296.0",a) == 0){
    x[1]=0x41F00000;
  }
  return v;
}

typedef int tcc_wtype;
typedef unsigned int tcc_uwtype;
typedef long long tcc_dwtype;
typedef unsigned long long tcc_udwtype;

struct tcc_dwstruct {
  tcc_wtype low;
  tcc_wtype high;
};

typedef union {
  struct tcc_dwstruct s;
  tcc_dwtype ll;
} tcc_dwunion;

typedef union {
  struct {
    tcc_uwtype low;
    tcc_uwtype high;
  } s;
  tcc_udwtype ll;
} tcc_udwunion;

static int tcc_udw_ge(tcc_udwtype a, tcc_udwtype b)
{
  tcc_udwunion ua;
  tcc_udwunion ub;
  ua.ll = a;
  ub.ll = b;
  if (ua.s.high != ub.s.high) {
    return ua.s.high > ub.s.high;
  }
  return ua.s.low >= ub.s.low;
}

static tcc_udwtype tcc_udw_sub(tcc_udwtype a, tcc_udwtype b)
{
  tcc_udwunion ua;
  tcc_udwunion ub;
  tcc_udwunion ur;
  ua.ll = a;
  ub.ll = b;
  ur.s.high = ua.s.high - ub.s.high;
  ur.s.low = ua.s.low - ub.s.low;
  if (ua.s.low < ub.s.low) {
    ur.s.high = ur.s.high - 1;
  }
  return ur.ll;
}

static tcc_udwtype tcc_udw_shl1(tcc_udwtype a)
{
  tcc_udwunion ua;
  ua.ll = a;
  ua.s.high = (ua.s.high << 1) | (ua.s.low >> 31);
  ua.s.low = ua.s.low << 1;
  return ua.ll;
}

static int tcc_udw_bit(tcc_udwtype a, int bit)
{
  tcc_udwunion ua;
  ua.ll = a;
  if (bit >= 32) {
    return (ua.s.high >> (bit - 32)) & 1;
  }
  return (ua.s.low >> bit) & 1;
}

static tcc_udwtype tcc_udw_set_bit(tcc_udwtype a, int bit)
{
  tcc_udwunion ua;
  ua.ll = a;
  if (bit >= 32) {
    ua.s.high = ua.s.high | ((tcc_uwtype)1 << (bit - 32));
  } else {
    ua.s.low = ua.s.low | ((tcc_uwtype)1 << bit);
  }
  return ua.ll;
}

static unsigned int tcc_half_byte(unsigned int b)
{
  unsigned int r;
  r = 0;
  if (b & 2) {
    r = r + 1;
  }
  if (b & 4) {
    r = r + 2;
  }
  if (b & 8) {
    r = r + 4;
  }
  if (b & 16) {
    r = r + 8;
  }
  if (b & 32) {
    r = r + 16;
  }
  if (b & 64) {
    r = r + 32;
  }
  if (b & 128) {
    r = r + 64;
  }
  return r;
}

static tcc_uwtype tcc_shr1_u32(tcc_uwtype x)
{
  unsigned char *p;
  unsigned int b0;
  unsigned int b1;
  unsigned int b2;
  unsigned int b3;
  p = (unsigned char *)&x;
  b0 = p[0];
  b1 = p[1];
  b2 = p[2];
  b3 = p[3];
  p[3] = tcc_half_byte(b3);
  p[2] = tcc_half_byte(b2);
  if (b3 & 1) {
    p[2] = p[2] + 128;
  }
  p[1] = tcc_half_byte(b1);
  if (b2 & 1) {
    p[1] = p[1] + 128;
  }
  p[0] = tcc_half_byte(b0);
  if (b1 & 1) {
    p[0] = p[0] + 128;
  }
  return x;
}

static tcc_uwtype tcc_sar1_u32(tcc_uwtype x)
{
  unsigned char *p;
  unsigned int b0;
  unsigned int b1;
  unsigned int b2;
  unsigned int b3;
  p = (unsigned char *)&x;
  b0 = p[0];
  b1 = p[1];
  b2 = p[2];
  b3 = p[3];
  p[3] = tcc_half_byte(b3);
  if (b3 & 128) {
    p[3] = p[3] + 128;
  }
  p[2] = tcc_half_byte(b2);
  if (b3 & 1) {
    p[2] = p[2] + 128;
  }
  p[1] = tcc_half_byte(b1);
  if (b2 & 1) {
    p[1] = p[1] + 128;
  }
  p[0] = tcc_half_byte(b0);
  if (b1 & 1) {
    p[0] = p[0] + 128;
  }
  return x;
}

static tcc_udwtype tcc_udivmoddi4(tcc_udwtype n, tcc_udwtype d, tcc_udwtype *rp)
{
  tcc_udwtype q;
  tcc_udwtype r;
  int i;
  q = 0;
  r = 0;
  if (d == 0) {
    puts("tcc udiv by zero");
    exit(1);
  }
  for (i = 63; i >= 0; --i) {
    r = tcc_udw_shl1(r);
    if (tcc_udw_bit(n, i)) {
      r = r | 1;
    }
    if (tcc_udw_ge(r, d)) {
      r = tcc_udw_sub(r, d);
      q = tcc_udw_set_bit(q, i);
    }
  }
  if (rp != 0) {
    *rp = r;
  }
  return q;
}

long long __divdi3(long long a, long long b)
{
  tcc_udwtype ua;
  tcc_udwtype ub;
  tcc_udwtype uq;
  int negate;
  negate = 0;
  if (a < 0) {
    ua = 0 - (tcc_udwtype)a;
    negate = !negate;
  } else {
    ua = a;
  }
  if (b < 0) {
    ub = 0 - (tcc_udwtype)b;
    negate = !negate;
  } else {
    ub = b;
  }
  uq = tcc_udivmoddi4(ua, ub, 0);
  if (negate) {
    return 0 - uq;
  }
  return uq;
}

long long __moddi3(long long a, long long b)
{
  tcc_udwtype ua;
  tcc_udwtype ub;
  tcc_udwtype ur;
  int negate;
  negate = 0;
  if (a < 0) {
    ua = 0 - (tcc_udwtype)a;
    negate = 1;
  } else {
    ua = a;
  }
  if (b < 0) {
    ub = 0 - (tcc_udwtype)b;
  } else {
    ub = b;
  }
  tcc_udivmoddi4(ua, ub, &ur);
  if (negate) {
    return 0 - ur;
  }
  return ur;
}

unsigned long long __udivdi3(unsigned long long a, unsigned long long b)
{
  return tcc_udivmoddi4(a, b, 0);
}

unsigned long long __umoddi3(unsigned long long a, unsigned long long b)
{
  tcc_udwtype ur;
  tcc_udivmoddi4(a, b, &ur);
  return ur;
}

long long __sardi3(long long a, int b)
{
  tcc_udwunion u;
  tcc_uwtype low;
  tcc_uwtype high;
  tcc_uwtype carry;
  int n;
  u.ll = a;
  low = u.s.low;
  high = u.s.high;
  n = b;
  while (n >= 32) {
    low = high;
    if (high & 0x80000000) {
      high = 0xFFFFFFFF;
    } else {
      high = 0;
    }
    n = n - 32;
  }
  while (n > 0) {
    carry = 0;
    if (high & 1) {
      carry = 0x80000000;
    }
    high = tcc_sar1_u32(high);
    low = tcc_shr1_u32(low) | carry;
    n = n - 1;
  }
  u.s.low = low;
  u.s.high = high;
  return u.ll;
}

unsigned long long __shrdi3(unsigned long long a, int b)
{
  tcc_udwunion u;
  tcc_uwtype low;
  tcc_uwtype high;
  tcc_uwtype carry;
  int n;
  u.ll = a;
  low = u.s.low;
  high = u.s.high;
  n = b;
  while (n >= 32) {
    low = high;
    high = 0;
    n = n - 32;
  }
  while (n > 0) {
    carry = 0;
    if (high & 1) {
      carry = 0x80000000;
    }
    high = tcc_shr1_u32(high);
    low = tcc_shr1_u32(low) | carry;
    n = n - 1;
  }
  u.s.low = low;
  u.s.high = high;
  return u.ll;
}

long long __shldi3(long long a, int b)
{
  tcc_udwunion u;
  tcc_uwtype low;
  tcc_uwtype high;
  tcc_uwtype carry;
  int n;
  u.ll = a;
  low = u.s.low;
  high = u.s.high;
  n = b;
  while (n >= 32) {
    high = low;
    low = 0;
    n = n - 32;
  }
  while (n > 0) {
    carry = 0;
    if (low & 0x80000000) {
      carry = 1;
    }
    low = low + low;
    high = high + high + carry;
    n = n - 1;
  }
  u.s.low = low;
  u.s.high = high;
  return u.ll;
}


int strlen(int p){
//  puts("strlen not impl");
  int l=0;
  char *s;
  s=(char *)p;
  while(s[0]){
    s=s+1;
    l=l+1;
  }
  return l;
}

int memset(int xi, int v, int size) {
/*  puts("unimpl memset"); err(); */
  int i;
  char *x;
  x=(char *)xi;
  for(i=0;i<size;i=i+1){
    x[i]=v;
  }
}

int strcpy(int d, int s) {
//  puts("strcpy not impl");
  int c;
  char *dest;
  char *src;
  dest=(char *)d;
  src=(char *)s;
  while((c=src[0])!=0){
    src=src+1;
    dest[0]=c;
    dest=dest+1;
  }
  dest[0]=0;
}

int strcmp(int a, int b){
  char *s1;
  char *s2;
  int i;
  int r;
  i=0;
  r=1;
  s1=(char *)a;
  s2=(char *)b;
  while(s1[i]!=0){
    r=0;
    if(s1[i]!=s2[i]){
      r=1;
      break;
    }
    i=i+1;
  }
  return r;
}

int strcat(int de,int s) {
  int d;
  char *dest;
  char *src;
  dest=(char *)de;
  src=(char *)s;
  d=dest;
  int c;
  while(dest[0]){
    dest=dest+1;
  }
  while(c=src[0]){
    src=src+1;
    dest[0]=c;
    dest=dest+1;
  }
  dest[0]=0;
  return d;
}

static int boot_vfprintf_impl(int stream, int format, int ap)
{
  char *fmt;
  char *args;
  int count;
  int c;
  fmt = (char *)format;
  args = (char *)ap;
  count = 0;
  while ((c = *fmt++) != 0) {
    if (c != '%') {
      fputc(c, stream);
      count = count + 1;
      continue;
    }
    c = *fmt++;
    if (c == 0) {
      break;
    }
    if (c == '%') {
      fputc('%', stream);
      count = count + 1;
    } else if (c == 's') {
      char *s;
      s = *(char **)args;
      args = args + sizeof(int);
      if (!s) {
        s = "(null)";
      }
      fputs(s, stream);
      count = count + strlen(s);
    } else if (c == 'd') {
      char *s;
      s = int2str(*(int *)args, 10, 1);
      args = args + sizeof(int);
      fputs(s, stream);
      count = count + strlen(s);
    } else if (c == 'u') {
      char *s;
      s = int2str(*(int *)args, 10, 0);
      args = args + sizeof(int);
      fputs(s, stream);
      count = count + strlen(s);
    } else if (c == 'c') {
      fputc(*(int *)args, stream);
      args = args + sizeof(int);
      count = count + 1;
    } else {
      fputc('%', stream);
      fputc(c, stream);
      count = count + 2;
    }
  }
  return count;
}

int memcmp(int s1, int s2, int n) {
  int i;
  int r;
  char *p1;
  char *p2;
  r=0;
  p1=(char *)s1;
  p2=(char *)s2;
  for(i=0;i<n;i=i+1){
    if(p1[i]!=p2[i]){
/* FIXME ljw not quite right */
      r=1;
    }
  }
  return r;
}

int memcpy(int a, int b, int c) {
  char *dest;
  char *src;
  int i;
  dest=(char *)a;
  src=(char *)b;
  for(i=0;i<c;i=i+1){
    dest[i]=src[i];
  }
}

static int boot_copy_rel_name(int dst, int suffix)
{
  int o;
  o = strcpy(dst, ".rel");
  o = strcat(dst, suffix);
  return o - dst;
}

static int boot_copy_label_name(int dst, int value)
{
  int o;
  o = strcpy(dst, "L.");
  o = strcat(dst, int2str(value, 10, 0));
  return o - dst;
}

static int boot_copy_format_name(int dst, int format, int value)
{
  if(strcmp(".rel%s", format) == 0) {
    return boot_copy_rel_name(dst, value);
  } else if(strcmp("L.%u", format) == 0) {
    return boot_copy_label_name(dst, value);
  } else {
    puts("unsupported bootstrap name format");
    exit(1);
  }
  return 0;
}

int memmove(void){
  puts("memmove not impl");
  exit(1);
}

int strrchr(int p, int c) {
  int c1;
  char *s;
  char *r;
  r=0;
  s=(char *)p;
  while(c1=s[0]){
    s=s+1;
    if(c1==c){
      r=s-1;
    }
  }
  return r;
}

int ldexp(void){
  puts("ldexp not impl");
  exit(1);
}

int getcwd(void){
  puts("getcwd not impl");
  exit(1);
}

int dlsym(void){
  puts("dlsym not impl");
  exit(1);
}

int fwrite(int ptr,int size, int nitems, int stream) {
/*
  puts("fwrite:");
  puts_num(ptr);
  puts_num(size);
  puts_num(nitems);
  puts_num(stream);
  puts("fwrite not impl");
  exit(1);
*/
  int t=size*nitems;
  char *c=(char *)ptr;
  while(t>0){
    fputc(c[0],stream);
    t=t-1;
    c=c+1;
  }
}

int lseek(void){
  puts("lseek not impl");
  exit(1);
}

int strtol(void){
  puts("strtol not impl");
  exit(1);
}

int strchr(void){
  puts("strchr not impl");
  exit(1);
}

int sigemptyset(void){
  puts("sigemptyset not impl");
  exit(1);
}

int sigaction(void){
  puts("sigaction not impl");
  exit(1);
}

int dlopen(void){
  puts("dlopen not impl");
  exit(1);
}

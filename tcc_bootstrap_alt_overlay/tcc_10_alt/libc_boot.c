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

        if(signed_p && (10 == base) && (0 != (x & 0x80000000)))
        {
                /* Truncate to 31bits */
                i = -x & 0x7FFFFFFF;
                if(0 == i) return "-2147483648";
                sign_p = 1;
        } /* Truncate to 32bits */
        else i = x & (0x7FFFFFFF | (1 << 31));

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

int fprintf(void){
  puts("fprintf not impl");
  exit(1);
}

int vfprintf(void){
  puts("vfprintf not impl");
  exit(1);
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

int sprintf(int a1, int a2, int a3, int a4, int a5, int a6){
  int format;
  int o;
  format = a2;
  fputs("sprintf \"", stdout);
  fputs(format, stdout);
  fputs("\"\n", stdout);
  if(strcmp(".rel%s", format) ==0) {
    puts("generating \".rel%s\" sprintf/snprintf string");
    fputs(".rel", stdout);
    fputs(a3,stdout);
    fputs("\n",stdout);
    o=strcpy(a1,".rel");
    o=strcat(a1, a3);
    return o-a1;
  } else if(strcmp("L.%u", format) ==0) {
    puts("generating \".L.%u\" sprintf/snprintf string");
    fputs("L.", stdout);
    /* FIXME leaky */
    fputs(int2str(a3, 10, 0), stdout);
    fputs("\n",stdout);
    o=strcpy(a1,"L.");
    o=strcat(a1, int2str(a3, 10, 0));
    return o-a1;
  } else {
    puts("unsupported sprintf/snprintf format string");
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

int snprintf(int a1, int a2, int a3, int a4, int a5, int a6){
  int format;
  int size;
  size = a2;
  format = a3;
  fputs("snprintf size: ", stdout);
  /* FIXME leaky */
  fputs(int2str(size, 10, 0), stdout);
  fputs(" format: \"", stdout);
  fputs(format, stdout);
  fputs("\"\n", stdout);
  sprintf(a1, a3, a4, a5, a6, 0);
  return 0;
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

int printf(int x){
  puts("printf not impl");
  exit(1);
}

typedef int tcc_dw_sword;
typedef unsigned int tcc_dw_uword;
typedef long long tcc_dw_slong;
typedef unsigned long long tcc_dw_ulong;

struct tcc_dw_words {
  tcc_dw_uword low;
  tcc_dw_sword high;
};

union tcc_dw_value {
  struct tcc_dw_words s;
  tcc_dw_slong sl;
  tcc_dw_ulong ul;
};

static tcc_dw_ulong tcc_pack_u64(tcc_dw_uword high, tcc_dw_uword low)
{
  union tcc_dw_value v;
  v.s.low = low;
  v.s.high = high;
  return v.ul;
}

static tcc_dw_slong tcc_pack_s64(tcc_dw_uword high, tcc_dw_uword low)
{
  union tcc_dw_value v;
  v.s.low = low;
  v.s.high = high;
  return v.sl;
}

static void tcc_unpack_u64(tcc_dw_ulong value, tcc_dw_uword *high, tcc_dw_uword *low)
{
  union tcc_dw_value v;
  v.ul = value;
  *low = v.s.low;
  *high = (tcc_dw_uword)v.s.high;
}

static int tcc_cmp_u64(tcc_dw_uword ah, tcc_dw_uword al,
                       tcc_dw_uword bh, tcc_dw_uword bl)
{
  if (ah < bh)
    return -1;
  if (ah > bh)
    return 1;
  if (al < bl)
    return -1;
  if (al > bl)
    return 1;
  return 0;
}

static void tcc_sub_u64(tcc_dw_uword *ah, tcc_dw_uword *al,
                        tcc_dw_uword bh, tcc_dw_uword bl)
{
  tcc_dw_uword new_low;
  tcc_dw_uword borrow;

  new_low = *al - bl;
  borrow = new_low > *al;
  *al = new_low;
  *ah = *ah - bh - borrow;
}

static void tcc_neg_u64(tcc_dw_uword *high, tcc_dw_uword *low)
{
  *low = ~*low + 1;
  *high = ~*high;
  if (*low == 0)
    *high = *high + 1;
}

static void tcc_shl1_u64(tcc_dw_uword *high, tcc_dw_uword *low)
{
  tcc_dw_uword carry;

  carry = *low & 0x80000000U;
  *high = *high + *high;
  if (carry)
    *high = *high + 1;
  *low = *low + *low;
}

static void tcc_set_bit_u64(tcc_dw_uword *high, tcc_dw_uword *low, int bit)
{
  tcc_dw_uword mask;

  mask = 1;
  if (bit >= 32) {
    bit = bit - 32;
    while (bit > 0) {
      mask = mask + mask;
      --bit;
    }
    *high = *high | mask;
  } else {
    while (bit > 0) {
      mask = mask + mask;
      --bit;
    }
    *low = *low | mask;
  }
}

static int tcc_get_bit_u64(tcc_dw_uword high, tcc_dw_uword low, int bit)
{
  tcc_dw_uword value;

  if (bit >= 32) {
    bit = bit - 32;
    value = high;
  } else {
    value = low;
  }

  while (bit > 0) {
    value = value / 2;
    --bit;
  }
  return value & 1;
}

static tcc_dw_ulong tcc_udivmod_u64(tcc_dw_ulong numer, tcc_dw_ulong denom,
                                    tcc_dw_ulong *remainder)
{
  tcc_dw_uword nh;
  tcc_dw_uword nl;
  tcc_dw_uword dh;
  tcc_dw_uword dl;
  tcc_dw_uword qh;
  tcc_dw_uword ql;
  tcc_dw_uword rh;
  tcc_dw_uword rl;
  int bit;

  tcc_unpack_u64(numer, &nh, &nl);
  tcc_unpack_u64(denom, &dh, &dl);

  qh = 0;
  ql = 0;
  rh = 0;
  rl = 0;

  if (dh == 0 && dl == 0) {
    if (remainder != 0)
      *remainder = 0;
    return 0;
  }

  for (bit = 63; bit >= 0; --bit) {
    tcc_shl1_u64(&rh, &rl);
    rl = rl | tcc_get_bit_u64(nh, nl, bit);
    if (tcc_cmp_u64(rh, rl, dh, dl) >= 0) {
      tcc_sub_u64(&rh, &rl, dh, dl);
      tcc_set_bit_u64(&qh, &ql, bit);
    }
  }

  if (remainder != 0)
    *remainder = tcc_pack_u64(rh, rl);
  return tcc_pack_u64(qh, ql);
}

long long __divdi3(long long a, long long b)
{
  union tcc_dw_value ua;
  union tcc_dw_value ub;
  tcc_dw_uword qh;
  tcc_dw_uword ql;
  int negative;

  ua.sl = a;
  ub.sl = b;
  negative = 0;

  if (ua.s.high < 0) {
    negative = !negative;
    tcc_neg_u64((tcc_dw_uword *)&ua.s.high, &ua.s.low);
  }
  if (ub.s.high < 0) {
    negative = !negative;
    tcc_neg_u64((tcc_dw_uword *)&ub.s.high, &ub.s.low);
  }

  tcc_unpack_u64(tcc_udivmod_u64(ua.ul, ub.ul, 0), &qh, &ql);
  if (negative)
    tcc_neg_u64(&qh, &ql);
  return tcc_pack_s64(qh, ql);
}

long long __moddi3(long long a, long long b)
{
  union tcc_dw_value ua;
  union tcc_dw_value ub;
  tcc_dw_ulong rem;
  tcc_dw_uword rh;
  tcc_dw_uword rl;
  int negative;

  ua.sl = a;
  ub.sl = b;
  negative = 0;

  if (ua.s.high < 0) {
    negative = 1;
    tcc_neg_u64((tcc_dw_uword *)&ua.s.high, &ua.s.low);
  }
  if (ub.s.high < 0)
    tcc_neg_u64((tcc_dw_uword *)&ub.s.high, &ub.s.low);

  tcc_udivmod_u64(ua.ul, ub.ul, &rem);
  tcc_unpack_u64(rem, &rh, &rl);
  if (negative)
    tcc_neg_u64(&rh, &rl);
  return tcc_pack_s64(rh, rl);
}

unsigned long long __udivdi3(unsigned long long a, unsigned long long b)
{
  return tcc_udivmod_u64(a, b, 0);
}

unsigned long long __umoddi3(unsigned long long a, unsigned long long b)
{
  tcc_dw_ulong rem;
  tcc_udivmod_u64(a, b, &rem);
  return rem;
}

long long __sardi3(long long a, int b)
{
  union tcc_dw_value u;
  tcc_dw_uword low;
  tcc_dw_sword high;
  int carry;
  int sign;

  u.sl = a;
  low = u.s.low;
  high = u.s.high;

  while (b > 0) {
    sign = high < 0;
    carry = high & 1;
    low = low / 2;
    if (carry)
      low = low | 0x80000000U;
    high = (tcc_dw_sword)((tcc_dw_uword)high / 2);
    if (sign)
      high = high | 0x80000000U;
    --b;
  }

  return tcc_pack_s64((tcc_dw_uword)high, low);
}

unsigned long long __shrdi3(unsigned long long a, int b)
{
  union tcc_dw_value u;
  tcc_dw_uword low;
  tcc_dw_uword high;
  int carry;

  u.ul = a;
  low = u.s.low;
  high = (tcc_dw_uword)u.s.high;

  while (b > 0) {
    carry = high & 1;
    low = low / 2;
    if (carry)
      low = low | 0x80000000U;
    high = high / 2;
    --b;
  }

  return tcc_pack_u64(high, low);
}

long long __shldi3(long long a, int b)
{
  union tcc_dw_value u;
  tcc_dw_uword low;
  tcc_dw_uword high;
  int carry;

  u.sl = a;
  low = u.s.low;
  high = (tcc_dw_uword)u.s.high;

  while (b > 0) {
    carry = low & 0x80000000U;
    high = high + high;
    if (carry)
      high = high | 1;
    low = low + low;
    --b;
  }

  return tcc_pack_s64(high, low);
}

/*
 *
 * This libc is cobbled together from various other libc libraries
 * includes parts of:
 *
 * https://github.com/oriansj/M2libc
 * http://git.savannah.gnu.org/cgit/mes.git/tree/?h=v0.25.1
 *
 * modifications are (C) 2023 Liam Wilson
 *
 * this libc is under the GPLv3 (same license as the libc libraries it derives
 * from)
 *
 */

extern int stdout;

int strcpy(int d, int s);
int strcat(int de,int s);

int puts(int x) {
  fputs(x, stdout);
  fputs("\n", stdout);
}

char* int2str(int x, int base, int signed_p)
{
        char* p = (char *)calloc(34, sizeof(char));
        if(0 == p) return p;

        p = p + 32;
        unsigned i;
        int sign_p = 0;
        char* table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if(signed_p && (10 == base) && (0 != (x & 0x80000000)))
        {
                i = -x & 0x7FFFFFFF;
                if(0 == i) return "-2147483648";
                sign_p = 1;
        } else i = x & (0x7FFFFFFF | (1 << 31));

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

double strtod(char *a, char **p){
  double v;
  int *x;
  x=&v;
  x[0]=0;
  x[1]=0;
  fputs("tcc strtod: ",stdout);
  fputs(a,stdout);
  fputs("\n",stdout);
  if(strcmp("4294967296.0",a) == 0){
    x[1]=0x41F00000;
  }
  if(strcmp("18446744073709551616.0",a) == 0){
    x[1]=0x43F00000;
  }
  if(strcmp("0.001",a) == 0){
    x[0]=0xD2F1A9FC;
    x[1]=0x3F50624D;
  }
  if(strcmp("1000000.0",a) == 0){
    x[1]=0x412E8480;
  }
  return v;
}

int strlen(int p){
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
  int i;
  char *x;
  x=(char *)xi;
  for(i=0;i<size;i=i+1){
    x[i]=v;
  }
}

int strcpy(int d, int s) {
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

#include <stdio.h>
#include <math.h>

int main() {
  char c;
  short s;
  int i;
  long l;
  long long ll;
  unsigned char uc;
  unsigned short us;
  unsigned int ui;
  unsigned long ul;
  unsigned long long ull;
  float f;
  double d;
  long double ld;

  c = s = i = l = ll = 0xc1c2c3c4c5c6c7c8;
  printf("%d %llx %lld\n", sizeof(ll), ll, ll);
  printf("%d %lx %ld\n", sizeof(l), l, l);
  printf("%d %x %d\n", sizeof(i), i, i);
  printf("%d %x %d\n", sizeof(s), s, s);
  printf("%d %x %d\n", sizeof(c), c, c);

  ll = l = i = s = c;
  printf("%d %x %d\n", sizeof(s), s, s);
  printf("%d %x %d\n", sizeof(i), i, i);
  printf("%d %lx %ld\n", sizeof(l), l, l);
  printf("%d %llx %lld\n", sizeof(ll), ll, ll);
  
  i = 1 << (sizeof(i) * 8 - 1);
  printf("%d %x %d\n", sizeof(i), i, i);
  i >>= 1;
  printf("%d %x %d\n", sizeof(i), i, i);
  i = -1;
  printf("%d %x %d\n", sizeof(i), i, i);
  i >>= 1;
  printf("%d %x %d\n", sizeof(i), i, i);

  uc = us = ui = ul = ull = 0xc1c2c3c4c5c6c7c8;
  printf("%d %llx %llu\n", sizeof(ull), ull, ull);
  printf("%d %lx %lu\n", sizeof(ul), ul, ul);
  printf("%d %x %u\n", sizeof(ui), ui, ui);
  printf("%d %x %u\n", sizeof(us), us, us);
  printf("%d %x %u\n", sizeof(uc), uc, uc);
  ull = ul = ui = us = uc;
  printf("%d %x %u\n", sizeof(us), us, us);
  printf("%d %x %u\n", sizeof(ui), ui, ui);
  printf("%d %lx %lu\n", sizeof(ul), ul, ul);
  printf("%d %llx %llu\n", sizeof(ull), ull, ull);

  f = d = ld = acosl(-1);
  printf("%2d %80.78llf\n", sizeof(ld), ld);
  printf("%2d %80.78lf\n", sizeof(d), d);
  printf("%2d %80.78f\n", sizeof(f), f);

  return 0;
}
/* Explanation of program's output for a LP64 architecture: 

8 c1c2c3c4c5c6c7c8 -4484807029008447544 
8 c1c2c3c4c5c6c7c8 -4484807029008447544
4 c5c6c7c8 -976828472 
2 ffffc7c8 -14392 
1 ffffffc8 -56
2 ffffffc8 -56
4 ffffffc8 -56
8 ffffffffffffffc8 -56
8 ffffffffffffffc8 -56
4 80000000 -2147483648
4 c0000000 -1073741824 
4 ffffffff -1 
4 ffffffff -1 
8 c1c2c3c4c5c6c7c8 13961937044701104072 
8 c1c2c3c4c5c6c7c8 13961937044701104072
4 c5c6c7c8 3318138824
2 c7c8 51144
1 c8 200
2 c8 200
4 c8 200
8 c8 200
8 c8 200
16 3.141592653589793238512808959406186204432742670178413391113281250000000000000000 
 8 3.141592653589793115997963468544185161590576171875000000000000000000000000000000 
 4 3.141592741012573242187500000000000000000000000000000000000000000000000000000000

*/


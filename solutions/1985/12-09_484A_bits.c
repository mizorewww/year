/* Codeforces 484A - Bits
 * https://codeforces.com/problemset/problem/484/A
 * rating: 1700 | tags: bitmasks, constructive algorithms
 * source: accepted submission #8570626 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main()
{
  int n; scanf ("%d", &n);

  int i;
  for (i = 0; i < n; ++i)
    {
      long long l, r;
      scanf("%I64d%I64d", &l, &r);

      int j;
      for(j = 0; j < 64; ++j)
        {
	  unsigned long long bit = 1LL << j;
	  unsigned long long x;
	  x = bit | l;
	  if(x <= r)
	    l = x;
        }

      printf("%I64d\n", l);
    }

  return 0;
}

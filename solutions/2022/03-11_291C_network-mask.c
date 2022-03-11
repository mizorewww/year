/* Codeforces 291C - Network Mask
 * https://codeforces.com/problemset/problem/291/C
 * rating: 1600 | tags: *special, bitmasks, brute force, implementation
 * source: accepted submission #3537133 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

int intcmp(const void *x, const void *y)
{
	if ( *(unsigned *) x < *(unsigned *) y )
		return -1;
	else
		return *(unsigned *) x > *(unsigned *) y;
}

int getip()
{
	int a, b, c, d;
	scanf("%d.%d.%d.%d", &a, &b, &c, &d);
	return a << 24 | b << 16 | c << 8 | d;
}

int na, nd, a[1<<20];

int main()
{
	int i, j, mask;
	scanf("%d%d", &na, &nd);
	for ( i = 0; i < na; ++i )
		a[i] = getip();
	qsort(a, na, sizeof(*a), intcmp);
	for ( mask = -(1<<31); mask != -1; mask >>= 1 )
	{
		for ( i = j = 0; i < na; ++i )
			if ( !i || (a[i]^a[i-1]) & mask )
				++j;
		if ( j == nd )
			break;
	}
	if ( mask == -1 )
		puts("-1");
	else
		printf("%d.%d.%d.%d\n", mask >> 24 & 255,
			mask >> 16 & 255, mask >> 8 & 255, mask & 255);
	return 0;
}

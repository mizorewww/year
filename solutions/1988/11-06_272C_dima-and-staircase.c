/* Codeforces 272C - Dima and Staircase
 * https://codeforces.com/problemset/problem/272/C
 * rating: 1500 | tags: data structures, implementation
 * source: accepted submission #3112931 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int n, a[1<<20];

int main()
{
	int i, j, nb;
	long long height = 0;
	scanf("%d", &n);
	for ( i = 0; i < n; ++i )
		scanf("%d", a+i);
	scanf("%d", &nb);
	while ( nb-- )
	{
		int w, h;
		scanf("%d%d", &w, &h);
		if ( height < a[w-1] )
			height = a[w-1];
		printf("%I64d\n", height);
		height += h;
	}
	return 0;
}

/* Codeforces 286C - Main Sequence
 * https://codeforces.com/problemset/problem/286/C
 * rating: 2100 | tags: greedy, implementation
 * source: accepted submission #3391477 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int n, a[1<<20];
int ns, s[1<<20];
char neg[1<<20];

int main()
{
	int i, j;
	scanf("%d", &n);
	for ( i = 0; i < n; ++i )
		scanf("%d", a+i);
	scanf("%d", &j);
	while ( j-- )
	{
		scanf("%d", &i);
		neg[--i] = 1;
	}
	for ( i = n; --i >= 0; )
	{
		if ( !ns || a[i] != s[ns-1] || neg[i] )
		{
			s[ns++] = a[i];
			a[i] = -a[i];
		}
		else
			--ns;
	}
	if ( ns )
		puts("NO");
	else
	{
		puts("YES");
		for ( i = 0; i < n; ++i )
			printf(" %d"+!i, a[i]);
		puts("");
	}
	return 0;
}

/* Codeforces 295B - Greg and Graph
 * https://codeforces.com/problemset/problem/295/B
 * rating: 1700 | tags: dp, graphs, shortest paths
 * source: accepted submission #3510047 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

int n, x[512], d[512][512];
long long rr[512];

int main()
{
	int i, j, k;
	long long res = 0;
	scanf("%d", &n);
	for ( i = 0; i < n; ++i )
		for ( j = 0; j < n; ++j )
			scanf("%d", d[i]+j);
	for ( i = n; --i >= 0; --x[i] )
		scanf("%d", x+i);
	for ( k = 0; k < n; ++k )
	{
		int ii, jj, kk = x[k];
		for ( i = 0; i < n; ++i )
		{
			ii = x[i];
			for ( j = 0; j < n; ++j )
			{
				jj = x[j];
				if ( d[ii][kk] + d[kk][jj] < d[ii][jj] )
					d[ii][jj] = d[ii][kk] + d[kk][jj];
			}
		}
		for ( res = i = 0; i <= k; ++i )
			for ( j = 0; j <= k; ++j )
				res += d[x[i]][x[j]];
		rr[k] = res;
	}
	for ( i = n; --i > 0; )
		printf("%I64d ", rr[i]);
	printf("%I64d\n", rr[i]);
	return 0;
}

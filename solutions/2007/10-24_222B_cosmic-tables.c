/* Codeforces 222B - Cosmic Tables
 * https://codeforces.com/problemset/problem/222/B
 * rating: 1300 | tags: data structures, implementation
 * source: accepted submission #2112323 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

int ma[1010][1010];
int row[1010], col[1010];

int main()
{
	int i,j,x,y,n,m,k;

	scanf("%d %d %d", &n, &m, &k);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%d", &ma[i][j]);

	for (i=1;i<=n;i++) row[i] = i;
	for (i=1;i<=m;i++) col[i] = i;
	
	scanf("\n");

	for (;k;k--)
	{
		char c;
		scanf("%c %d %d\n", &c, &x, &y);

		if (c=='g')
		{
			printf("%d\n", ma[row[x]][col[y]]);
		}
		else if (c=='r')
		{
			int t = row[x];
			row[x] = row[y];
			row[y] = t;
		}
		else
		{
			int t = col[x];
			col[x] = col[y];
			col[y] = t;
		}
	}

	return 0;
}

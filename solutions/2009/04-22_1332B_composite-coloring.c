/* Codeforces 1332B - Composite Coloring
 * https://codeforces.com/problemset/problem/1332/B
 * rating: 1400 | tags: brute force, constructive algorithms, greedy, math, number theory
 * source: accepted submission #74940112 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int n;
	int i, j;
	int a[1003];
	int p[11] = { 2,3,5,7,11,13,17,19,23,29,31 };
	int ans[1003];
	int c[11];
	int m;
	for (; t > 0; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 11; j++)
			{
				if (a[i] % p[j] == 0)
				{
					ans[i] = j;
					break;
				}
			}
		}
		for (i = 0; i < 11; i++)
			c[i] = 0;
		for (i = 0; i < n; i++)
			c[ans[i]]++;
		m = 0;
		for (i = 0; i < 11; i++)
			if (c[i] > 0)
				m++;
		printf("%d\n", m);
		m = 1;
		for (i = 0; i < 11; i++)
		{
			if (c[i] > 0)
			{
				c[i] = m;
				m++;
			}
		}
		for (i = 0; i < n - 1; i++)
			printf("%d ", c[ans[i]]);
		printf("%d\n", c[ans[n - 1]]);
	}
	return 0;
}

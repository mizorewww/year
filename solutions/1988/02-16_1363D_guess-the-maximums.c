/* Codeforces 1363D - Guess The Maximums
 * https://codeforces.com/problemset/problem/1363/D
 * rating: 2100 | tags: binary search, implementation, interactive, math
 * source: accepted submission #82124984 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int n, k;
	int i, j;
	int c[1003], s[1003];
	int max;
	int l, r, m;
	int x;
	int ans[1003];
	char res[102];
	int u[1003];
	for (; t > 0; t--)
	{
		scanf("%d %d", &n, &k);
		c[0] = 0;
		for (i = 0; i < k; i++)
		{
			scanf("%d", &x);
			c[i + 1] = c[i] + x;
			for (j = c[i]; j < c[i + 1]; j++)
				scanf("%d", &s[j]);
		}
		printf("? %d", n);
		for (i = 0; i < n; i++)
			printf(" %d", i + 1);
		printf("\n");
		fflush(stdout);
		scanf("%d", &max);
		if (max < 0)
			return 0;
		l = 1;
		r = n + 1;
		while (l + 1 < r)
		{
			m = (l + r) / 2;
			printf("? %d", m - l);
			for (i = l; i < m; i++)
				printf(" %d", i);
			printf("\n");
			fflush(stdout);
			scanf("%d", &x);
			if (x < 0)
				return 0;
			if (x == max)
				r = m;
			else
				l = m;
		}
		for (i = 0; i < k; i++)
			ans[i] = max;
		x = -1;
		for (j = 0; j < k; j++)
			for (i = c[j]; i < c[j + 1]; i++)
				if (s[i] == l)
					x = j;
		if (x >= 0)
		{
			for (i = 0; i < n; i++)
				u[i + 1] = 0;
			for (i = c[x]; i < c[x + 1]; i++)
				u[s[i]] = 1;
			printf("? %d", n - c[x + 1] + c[x]);
			for (i = 1; i <= n; i++)
				if (u[i] == 0)
					printf(" %d", i);
			printf("\n");
			fflush(stdout);
			scanf("%d", &ans[x]);
			if (ans[x] < 0)
				return 0;
		}
		printf("!");
		for (i = 0; i < k; i++)
			printf(" %d", ans[i]);
		printf("\n");
		fflush(stdout);
		scanf("%s", res);
		if (res[0] == 'I')
			return 0;
	}
	return 0;
}

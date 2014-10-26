/* Codeforces 1217B - Zmei Gorynich
 * https://codeforces.com/problemset/problem/1217/B
 * rating: 1600 | tags: greedy, math
 * source: accepted submission #60101018 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int i, j;
	int n, x;
	int d, h;
	int maxd, maxdh;
	for (j = 0; j < t; j++)
	{
		scanf("%d %d", &n, &x);
		maxd = 0;
		maxdh = -1000000009;
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &d, &h);
			if (maxd < d)maxd = d;
			if (maxdh < d - h)maxdh = d - h;
		}
		if (x > maxd && maxdh <= 0)
			printf("-1\n");
		else
		{
			if (x <= maxd)
				printf("1\n");
			else
				printf("%d\n", 1 + (x - maxd + maxdh - 1) / maxdh);
		}
	}
	return 0;
}

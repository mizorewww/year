/* Codeforces 1184B1 - The Doctor Meets Vader (Easy)
 * https://codeforces.com/problemset/problem/1184/B1
 * rating: 1400 | tags: binary search, sortings
 * source: accepted submission #56652244 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
int d[100005], g[100005];
int asc(const void* a, const void* b)
{
	return d[*(int*)a] - d[*(int*)b];
}
int main()
{
	int s, b;
	scanf("%d %d", &s, &b);
	int i;
	int a[100005];
	for (i = 0; i < s; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < b; i++)
		scanf("%d %d", &d[i], &g[i]);
	int c[100005];
	for (i = 0; i < b; i++)
		c[i] = i;
	qsort(c, b, sizeof(int), asc);
	int sum[100005];
	sum[0] = 0;
	for (i = 0; i < b; i++)
		sum[i + 1] = sum[i] + g[c[i]];
	int min, mid, max;
	int ans[100005];
	for (i = 0; i < s; i++)
	{
		if (a[i] < d[c[0]])
			ans[i] = 0;
		else if (a[i] >= d[c[b - 1]])
			ans[i] = sum[b];
		else
		{
			min = 0;
			max = b - 1;
			while (max - min > 1)
			{
				mid = (max + min) / 2;
				if (d[c[mid]] > a[i])
					max = mid;
				else
					min = mid;
			}
			ans[i] = sum[max];
		}
	}
	for (i = 0; i < s - 1; i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[s - 1]);
	return 0;
}

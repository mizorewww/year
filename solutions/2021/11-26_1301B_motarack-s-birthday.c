/* Codeforces 1301B - Motarack's Birthday
 * https://codeforces.com/problemset/problem/1301/B
 * rating: 1500 | tags: binary search, greedy, ternary search
 * source: accepted submission #70970263 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
long long int abs(long long int n)
{
	if (n < 0)
		n *= -1;
	return n;
}
int main()
{
	int t;
	scanf("%d", &t);
	int n;
	long long int a[100005];
	int i;
	long long int min, max;
	long long int m, k;
	for (; t > 0; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		min = 1000000009;
		max = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (a[i] < 0 && a[i + 1] >= 0)
			{
				if (min > a[i + 1])
					min = a[i + 1];
				if (max < a[i + 1])
					max = a[i + 1];
			}
			if (a[i] >= 0 && a[i + 1] < 0)
			{
				if (min > a[i])
					min = a[i];
				if (max < a[i])
					max = a[i];
			}
		}
		k = (max + min) / 2;
		for (i = 0; i < n; i++)
			if (a[i] < 0)
				a[i] = k;
		m = 0;
		for (i = 0; i < n - 1; i++)
			if (m < abs(a[i] - a[i + 1]))
				m = abs(a[i] - a[i + 1]);
		printf("%lld %lld\n", m, k);
	}
	return 0;
}

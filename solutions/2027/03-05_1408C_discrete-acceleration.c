/* Codeforces 1408C - Discrete Acceleration
 * https://codeforces.com/problemset/problem/1408/C
 * rating: 1500 | tags: binary search, dp, implementation, math, two pointers
 * source: accepted submission #94325115 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int n, l;
	int i;
	int a[100005];
	double t1[100005], t2[100005];
	for (; t > 0; t--)
	{
		scanf("%d %d", &n, &l);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i + 1]);
		a[0] = 0;
		a[n + 1] = l;
		t1[0] = 0;
		for (i = 1; i < n + 2; i++)
			t1[i] = t1[i - 1] + (a[i] - a[i - 1]) / (double)i;
		t2[n + 1] = 0;
		for (i = n; i >= 0; i--)
			t2[i] = t2[i + 1] + (a[i + 1] - a[i]) / (double)(n + 1 - i);
		i = 0;
		while (t1[i] < t2[i])
			i++;
		if (t1[i - 1] < t2[i])
			printf("%.20f\n", t2[i] + (a[i] - a[i - 1] - i * (t2[i] - t1[i - 1])) / (double)(n + 2));
		else
			printf("%.20f\n", t1[i - 1] + (a[i] - a[i - 1] - (n + 2 - i) * (t1[i - 1] - t2[i])) / (double)(n + 2));
	}
	return 0;
}

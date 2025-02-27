/* Codeforces 913C - Party Lemonade
 * https://codeforces.com/problemset/problem/913/C
 * rating: 1600 | tags: bitmasks, dp, greedy
 * source: accepted submission #34018844 (GNU C) downloaded from Codeforces
 */

#include <limits.h>
#include <stdio.h>

#define N 31

int main() {
	static long long cc[N];
	long long min, sum;
	int n, k, l, i, h;

	scanf("%d%d", &n, &l);
	for (i = 0; i < n; i++)
		scanf("%lld", &cc[i]);
	for (i = 1; i < N; i++)
		if (i >= n || cc[i] > cc[i - 1] * 2LL)
			cc[i] = cc[i - 1] * 2LL;
	min = LLONG_MAX;
	sum = 0;
	k = 0;
	for (h = N - 1; h >= 0; h--)
		if ((l & 1 << h) > 0) {
			k |= 1 << h;
			sum += cc[h];
			if (k == l && min > sum)
				min = sum;
		} else
			if (min > sum + cc[h])
				min = sum + cc[h];
	printf("%lld\n", min);
	return 0;
}

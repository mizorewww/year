/* Codeforces 1486D - Max Median
 * https://codeforces.com/problemset/problem/1486/D
 * rating: 2100 | tags: binary search, data structures, dp
 * source: accepted submission #107844555 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define N	200000

int min(int a, int b) { return a < b ? a : b; }

int solve(int *aa, int n, int k, int a) {
	static int pp[N];
	int i, p;

	p = 0;
	for (i = 0; i < n; i++)
		pp[i] = p += aa[i] >= a ? 1 : -1;
	p = 0;
	for (i = k - 1; i < n; i++) {
		if (pp[i] - p > 0)
			return 1;
		p = min(p, pp[i - k + 1]);
	}
	return 0;
}

int main() {
	static int aa[N];
	int n, k, i, lower, upper;

	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	lower = 1, upper = n + 1;
	while (upper - lower > 1) {
		int a = (lower + upper) / 2;

		if (solve(aa, n, k, a))
			lower = a;
		else
			upper = a;
	}
	printf("%d\n", lower);
	return 0;
}

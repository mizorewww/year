/* Codeforces 1370E - Binary Subsequence Rotation
 * https://codeforces.com/problemset/problem/1370/E
 * rating: 2100 | tags: binary search, constructive algorithms, data structures, greedy
 * source: accepted submission #84478531 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define N	1000000

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
	static char aa[N + 1], bb[N + 1];
	int n, i, dmin, dmax, dmin_, dmax_, dsum;

	scanf("%d%s%s", &n, aa, bb);
	dsum = dmin_ = dmax_ = dmin = dmax = 0;
	for (i = 0; i < n; i++) {
		int d = (aa[i] == '0' ? 1 : 0) - (bb[i] == '0' ? 1 : 0);

		dsum += d;
		dmin_ = min(dmin_, dmin = min(dmin + d, 0));
		dmax_ = max(dmax_, dmax = max(dmax + d, 0));
	}
	printf("%d\n", dsum == 0 ? max(dmax_, -dmin_) : -1);
	return 0;
}

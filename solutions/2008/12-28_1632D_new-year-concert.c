/* Codeforces 1632D - New Year Concert
 * https://codeforces.com/problemset/problem/1632/D
 * rating: 2000 | tags: binary search, data structures, greedy, math, number theory, two pointers
 * source: accepted submission #144543200 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define N	200000
#define K	31	/* K = ceil(log2(10^9)) + 1 */

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	static int aa[N], ii[K], dd[K];
	int n, k, k_, h, i, x, ans;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	k = 0, x = -1, ans = 0;
	for (i = 0; i < n; i++) {
		ii[k] = i, dd[k] = aa[i], k++;
		for (h = k - 2; h >= 0; h--)
			dd[h] = gcd(dd[h], dd[h + 1]);
		k_ = 0;
		for (h = 0; h < k; h++)
			if (k_ == 0 || dd[k_ - 1] != dd[h])
				ii[k_] = ii[h], dd[k_] = dd[h], k_++;
		k = k_;
		for (h = k - 1; h >= 0; h--) {
			int l = i - dd[h] + 1;

			if (l >= ii[h] && (h + 1 == k || l < ii[h + 1]) && x < l)
				x = i, ans++;
		}
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}

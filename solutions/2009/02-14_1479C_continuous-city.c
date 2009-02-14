/* Codeforces 1479C - Continuous City
 * https://codeforces.com/problemset/problem/1479/C
 * rating: 2500 | tags: bitmasks, constructive algorithms
 * source: accepted submission #106783557 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define M	496

int main() {
	static int ii[M], jj[M], ww[M];
	int n, m, l, r, k, i, j;

	scanf("%d%d", &l, &r), k = r - l + 1;
	n = 2;
	while (1 << n - 2 < k)
		n++;
	m = 0;
	for (i = 1; i < n - 1; i++) {
		ii[m] = n - 1 - i, jj[m] = n - 1, ww[m] = 1, m++;
		for (j = 1; j < i; j++)
			ii[m] = n - 1 - i, jj[m] = n - 1 - j, ww[m] = 1 << j - 1, m++;
	}
	i = n - 1;
	for (j = i - 1; j >= 0; j--) {
		int k_ = j == 0 ? 0 : 1 << j - 1;

		if (k > k_) {
			ii[m] = n - 1 - i, jj[m] = n - 1 - j, ww[m] = k - k_, m++;
			k -= k_;
		}
	}
	if (l > 1) {
		n++;
		ii[m] = n - 2, jj[m] = n - 1, ww[m] = l - 1, m++;
	}
	printf("YES\n");
	printf("%d %d\n", n, m);
	while (m--)
		printf("%d %d %d\n", ii[m] + 1, jj[m] + 1, ww[m]);
	return 0;
}

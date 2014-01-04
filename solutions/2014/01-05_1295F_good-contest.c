/* Codeforces 1295F - Good Contest
 * https://codeforces.com/problemset/problem/1295/F
 * rating: 2700 | tags: combinatorics, dp, probabilities
 * source: accepted submission #69756693 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

#define N	50
#define MD	998244353

int compare(const void *a, const void *b) {
	int ia = *(int *) a;
	int ib = *(int *) b;

	return ia - ib;
}

int x_, y_, d_;

void gcd_(int a, int b) {
	if (b == 0)
		x_ = 1, y_ = 0, d_ = 0;
	else {
		int t;

		gcd_(b, a % b);
		t = x_ - a / b * y_, x_ = y_, y_ = t;
	}
}

int inv(int a) {
	gcd_(a, MD);
	if (x_ < 0)
		x_ += MD;
	return x_;
}

int choose(int n, int k) {
	return k == 0 ? 1 : (long long) choose(n - 1, k - 1) * n % MD * inv(k) % MD;
}

int main() {
	static int ll[N], rr[N], uu[N + 1], vv[N], dp[N + 1][N * 2], xx[N * 2];
	int n, m, i, i_, j, j_, ans;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		uu[i] = inv(i);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &ll[i], &rr[i]), rr[i]++;
		xx[i * 2 + 0] = ll[i];
		xx[i * 2 + 1] = rr[i];
		vv[i] = inv(rr[i] - ll[i]);
	}
	qsort(xx, n * 2, sizeof *xx, compare);
	m = 0;
	for (i = 0; i < n * 2; i++)
		if (m == 0 || xx[m - 1] != xx[i])
			xx[m++] = xx[i];
	dp[0][m - 1] = 1;
	for (i = 0; i < n; i++)
		for (j = 1; j < m; j++) {
			int x = dp[i][j];

			if (x == 0)
				continue;
			for (j_ = j - 1; j_ >= 0; j_--) {
				int l = xx[j_], r = xx[j_ + 1];
				int v = 1, c = 1;

				for (i_ = i; i_ < n && ll[i_] <= l && r <= rr[i_]; i_++) {
					v = (long long) v * vv[i_] % MD;
					c = (long long) c * (i_ - i + 1 + r - l - 1) % MD * uu[i_ - i + 1] % MD;
					dp[i_ + 1][j_] = (dp[i_ + 1][j_] + (long long) x * c % MD * v) % MD;
				}
			}
		}
	ans = 0;
	for (j = 0; j < m - 1; j++)
		ans = (ans + dp[n][j]) % MD;
	printf("%d\n", ans);
	return 0;
}

/* Codeforces 1613F - Tree Coloring
 * https://codeforces.com/problemset/problem/1613/F
 * rating: 2600 | tags: combinatorics, divide and conquer, fft
 * source: accepted submission #137645159 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

#define N	250000
#define L_	18	/* L_ = pow2(ceil(log2(N + 1))) */
#define N_	(1 << L_)
#define MD	998244353

long long power(long long a, int k) {
	long long p = 1;

	while (k) {
		if (k & 1)
			p = p * a % MD;
		a = a * a % MD;
		k >>= 1;
	}
	return p;
}

int *wwu[L_ + 1], *wwv[L_ + 1], vv[L_ + 1];
int ff[N + 1];

void init() {
	int i, l, u, v;

	ff[0] = 1;
	for (i = 1; i <= N; i++)
		ff[i] = (long long) ff[i - 1] * i % MD;
	u = power(3, MD - 1 >> L_), v = power(u, MD - 2);
	for (l = L_; l >= 0; l--) {
		int n = 1 << l, m = n >> 1, i;

		vv[l] = power(n, MD - 2);
		wwu[l] = (int *) malloc(m * sizeof *wwu[l]);
		wwv[l] = (int *) malloc(m * sizeof *wwv[l]);
		wwu[l][0] = wwv[l][0] = 1;
		for (i = 1; i < m; i++) {
			wwu[l][i] = (long long) wwu[l][i - 1] * u % MD;
			wwv[l][i] = (long long) wwv[l][i - 1] * v % MD;
		}
		u = (long long) u * u % MD, v = (long long) v * v % MD;
	}
}

int *pp[N * 2], nn[N * 2];

void ntt_(int *aa, int l, int inverse) {
	if (l) {
		int n = 1 << l, m = n >> 1, *ww = inverse ? wwv[l] : wwu[l], i, j;

		ntt_(aa, l - 1, inverse), ntt_(aa + m, l - 1, inverse);
		for (i = 0; (j = i + m) < n; i++) {
			int a = aa[i], b = (long long) aa[j] * ww[i] % MD;

			if ((aa[i] = a + b) >= MD)
				aa[i] -= MD;
			if ((aa[j] = a - b) < 0)
				aa[j] += MD;
		}
	}
}

void ntt(int *aa, int l, int inverse) {
	int n = 1 << l, i, j;

	for (i = 0, j = 1; j < n; j++) {
		int b = n >> 1, tmp;

		while ((i ^= b) < b)
			b >>= 1;
		if (i < j)
			tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
	}
	ntt_(aa, l, inverse);
}

int *multiply(int *aa, int n, int *bb, int m) {
	static int aa_[N_], bb_[N_];
	int *cc, n_, l_, i;

	l_ = 0;
	while (1 << l_ < n + m - 1)
		l_++;
	n_ = 1 << l_;
	for (i = 0; i < n_; i++) {
		aa_[i] = i < n ? aa[i] : 0;
		bb_[i] = i < m ? bb[i] : 0;
	}
	ntt(aa_, l_, 0);
	ntt(bb_, l_, 0);
	for (i = 0; i < n_; i++)
		aa_[i] = (long long) aa_[i] * bb_[i] % MD;
	ntt(aa_, l_, 1);
	cc = malloc((n + m - 1) * sizeof *cc);
	for (i = 0; i < n + m - 1; i++)
		cc[i] = (long long) aa_[i] * vv[l_] % MD;
	return cc;
}

int main() {
	static int dd[N];
	int n, h, i, j, k, ans, head, cnt;

	init();
	scanf("%d", &n);
	dd[0]++;
	for (h = 0; h < n - 1; h++) {
		scanf("%d%d", &i, &j), i--, j--;
		dd[i]++, dd[j]++;
	}
	cnt = 0;
	for (i = 0; i < n; i++) {
		pp[i] = (int *) malloc((nn[i] = 2) * sizeof *pp[i]);
		pp[i][0] = 1, pp[i][1] = dd[i] - 1;
	}
	head = 0, cnt = n;
	while (cnt >= 2) {
		pp[head + cnt] = multiply(pp[head], nn[head], pp[head + 1], nn[head + 1]);
		nn[head + cnt] = nn[head] + nn[head + 1] - 1;
		head += 2, cnt--;
	}
	ans = 0;
	for (k = 0; k <= n; k++)
		ans = (ans + (long long) pp[head][k] * ff[n - k] % MD * (k % 2 == 0 ? 1 : -1)) % MD;
	if (ans < 0)
		ans += MD;
	printf("%d\n", ans);
	return 0;
}

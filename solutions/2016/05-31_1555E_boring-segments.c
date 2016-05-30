/* Codeforces 1555E - Boring Segments
 * https://codeforces.com/problemset/problem/1555/E
 * rating: 2100 | tags: data structures, sortings, trees, two pointers
 * source: accepted submission #124307218 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <sys/time.h>

#define N	300000
#define N_	(1 << 20)	/* N_ = pow2(ceil(log2(1000000))) */
#define INF	0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

unsigned int X;

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	X = tv.tv_sec ^ tv.tv_usec | 1;
}

int rand_() {
	return (X *= 3) >> 1;
}

int ll[N], rr[N], ww[N];

void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;

		while (j < k)
			if (ww[ii[j]] == ww[i_])
				j++;
			else if (ww[ii[j]] < ww[i_]) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
			}
		sort(ii, l, i);
		l = k;
	}
}

int st[N_ * 2], lz[N_ * 2], n_;

void put(int i, int x) {
	st[i] += x, lz[i] += x;
}

void pul(int i) {
	st[i] = min(st[i << 1 | 0], st[i << 1 | 1]) + lz[i];
}

void pull(int i) {
	while (i > 1)
		pul(i >>= 1);
}

void build(int m) {
	int i;

	n_ = 1;
	while (n_ < m)
		n_ <<= 1;
	for (i = 0; i < n_; i++)
		st[n_ + i] = i < m ? 0 : 1;
	for (i = n_ - 1; i > 0; i--)
		pul(i);
}

void update(int l, int r, int x) {
	int l_ = l += n_, r_ = r += n_;

	for ( ; l <= r; l >>= 1, r >>= 1) {
		if ((l & 1) == 1)
			put(l++, x);
		if ((r & 1) == 0)
			put(r--, x);
	}
	pull(l_), pull(r_);
}

int main() {
	static int ii[N];
	int n, m, i, j, ans;

	srand_();
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &ll[i], &rr[i], &ww[i]), ll[i]--, rr[i] -= 2;
		ii[i] = i;
	}
	sort(ii, 0, n);
	build(m - 1);
	ans = INF;
	for (i = 0, j = 0; i < n; i++) {
		while (j < n && st[1] == 0)
			update(ll[ii[j]], rr[ii[j]], 1), j++;
		if (st[1] > 0)
			ans = min(ans, ww[ii[j - 1]] - ww[ii[i]]);
		update(ll[ii[i]], rr[ii[i]], -1);
	}
	printf("%d\n", ans);
	return 0;
}

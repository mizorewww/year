/* Codeforces 1548E - Gregor and the Two Painters
 * https://codeforces.com/problemset/problem/1548/E
 * rating: 3400 | tags: data structures, divide and conquer, graphs, greedy, math
 * source: accepted submission #124598455 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define N	200000
#define M	200000
#define K	(N * 2)
#define A	200000
#define INF	0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

unsigned int X;

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	X = tv.tv_sec ^ tv.tv_usec | 1;
}

int rand_() {
	return (X *= 3) >> 1;
}

int mn[N * 2], mx[N * 2], n_;

void pul(int i) {
	int l = i << 1, r = l | 1;

	mn[i] = min(mn[l], mn[r]), mx[i] = max(mx[l], mx[r]);
}

void build(int *aa, int n) {
	int i;

	n_ = n;
	for (i = 0; i < n; i++)
		mn[n_ + i] = mx[n_ + i] = aa[i];
	for (i = n_ - 1; i > 0; i--)
		pul(i);
}

void st_query(int l, int r, int *x, int *y) {
	*x = INF, *y = -INF;
	for (l += n_, r += n_; l <= r; l >>= 1, r >>= 1) {
		if ((l & 1) == 1)
			*x = min(*x, mn[l]), *y = max(*y, mx[l]), l++;
		if ((r & 1) == 0)
			*x = min(*x, mn[r]), *y = max(*y, mx[r]), r--;
	}
}

int kk[A + 1], ll[A + 1];

long long count_pairs(int s) {
	int a, l;
	long long ans;

	ans = 0, l = 0;
	for (a = s; a >= 0; a--)
		ans += (long long) kk[a] * (l += ll[s - a]);
	return ans;
}

long long count_vertices(int *aa, int n, int *bb, int m, int s) {
	int i, j;

	memset(kk, 0, (A + 1) * sizeof *kk);
	for (i = 0; i < n; i++)
		kk[aa[i]]++;
	memset(ll, 0, (A + 1) * sizeof *ll);
	for (j = 0; j < m; j++)
		ll[bb[j]]++;
	return count_pairs(s);
}

long long count_edges(int *aa, int n, int *bb, int m, int s) {
	int i, j;
	long long e1, e2;

	memset(kk, 0, (A + 1) * sizeof *kk);
	for (i = 0; i < n; i++)
		kk[aa[i]]++;
	memset(ll, 0, (A + 1) * sizeof *ll);
	for (j = 0; j < m - 1; j++)
		ll[max(bb[j], bb[j + 1])]++;
	e1 = count_pairs(s);
	memset(kk, 0, (A + 1) * sizeof *kk);
	for (i = 0; i < n - 1; i++)
		kk[max(aa[i], aa[i + 1])]++;
	memset(ll, 0, (A + 1) * sizeof *ll);
	for (j = 0; j < m; j++)
		ll[bb[j]]++;
	e2 = count_pairs(s);
	return e1 + e2;
}

int xx[K], yyl[K], yyr[K], yy[K], xxl[K], xxr[K], hh[K * 3], qu[N], k1, k2;

int get_x(int h) {
	return h < k1 ? xx[h] : (((h - k1) & 1) == 0 ? xxl[h - k1 >> 1] : xxr[h - k1 >> 1]);
}

int compare(int h1, int h2) {
	int x1 = get_x(h1), x2 = get_x(h2);

	return x1 != x2 ? x1 - x2 : h1 - h2;
}

void sort(int *hh, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, h = hh[l + rand_() % (r - l)], tmp;

		while (j < k) {
			int c = compare(hh[j], h);

			if (c == 0)
				j++;
			else if (c < 0) {
				tmp = hh[i], hh[i] = hh[j], hh[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = hh[j], hh[j] = hh[k], hh[k] = tmp;
			}
		}
		sort(hh, l, i);
		l = k;
	}
}

int ft[A + 1];

void ft_update(int i, int x) {
	i = max(i, 0);
	while (i <= A) {
		ft[i] += x;
		i |= i + 1;
	}
}

int ft_query(int i) {
	int x = 0;

	i = min(i, A);
	while (i >= 0) {
		x += ft[i];
		i &= i + 1, i--;
	}
	return x;
}

long long count_faces(int *aa, int n, int *bb, int m, int s) {
	int i, j, cnt, h;
	long long ans;

	build(aa, n);
	cnt = 0, k1 = 0;
	for (i = 0; i < n; i++) {
		int a, amn, amx;

		while (cnt && aa[qu[cnt - 1]] >= aa[i]) {
			if (i - qu[cnt - 1] > 1) {
				a = max(aa[qu[cnt - 1]], aa[i]), st_query(qu[cnt - 1] + 1, i - 1, &amn, &amx);
				if (amn > a)
					xx[k1] = amx, yyl[k1] = s - amn, yyr[k1] = s - a, k1++;
			}
			cnt--;
		}
		if (cnt) {
			if (i - qu[cnt - 1] > 1) {
				a = max(aa[qu[cnt - 1]], aa[i]), st_query(qu[cnt - 1] + 1, i - 1, &amn, &amx);
				if (amn > a)
					xx[k1] = amx, yyl[k1] = s - amn, yyr[k1] = s - a, k1++;
			}
		}
		qu[cnt++] = i;
	}
	build(bb, m);
	cnt = 0, k2 = 0;
	for (j = 0; j < m; j++) {
		int b, bmn, bmx;

		while (cnt && bb[qu[cnt - 1]] >= bb[j]) {
			if (j - qu[cnt - 1] > 1) {
				b = max(bb[qu[cnt - 1]], bb[j]), st_query(qu[cnt - 1] + 1, j - 1, &bmn, &bmx);
				if (bmn > b)
					yy[k2] = bmx, xxl[k2] = s - bmn, xxr[k2] = s - b, k2++;
			}
			cnt--;
		}
		if (cnt) {
			if (j - qu[cnt - 1] > 1) {
				b = max(bb[qu[cnt - 1]], bb[j]), st_query(qu[cnt - 1] + 1, j - 1, &bmn, &bmx);
				if (bmn > b)
					yy[k2] = bmx, xxl[k2] = s - bmn, xxr[k2] = s - b, k2++;
			}
		}
		qu[cnt++] = j;
	}
	memset(kk, 0, (A + 1) * sizeof *kk);
	for (i = 0; i < n - 1; i++)
		kk[max(aa[i], aa[i + 1])]++;
	memset(ll, 0, (A + 1) * sizeof *ll);
	for (j = 0; j < m - 1; j++)
		ll[max(bb[j], bb[j + 1])]++;
	ans = 1 + count_pairs(s);
#if 0
	for (h1 = 0; h1 < k1; h1++)
		for (h2 = 0; h2 < k2; h2++)
			if (xxl[h2] < xx[h1] && xx[h1] <= xxr[h2] && yyl[h1] < yy[h2] && yy[h2] <= yyr[h1])
				ans++;
#endif
	for (h = 0; h < k1 + k2 * 2; h++)
		hh[h] = h;
	sort(hh, 0, k1 + k2 * 2);
	for (h = 0; h < k1 + k2 * 2; h++) {
		int h_ = hh[h];

		if (h_ < k1)
			ans += ft_query(yyr[h_]) - ft_query(yyl[h_]);
		else
			ft_update(yy[h_ - k1 >> 1], ((h_ - k1) & 1) == 0 ? 1 : -1);
	}
	return ans;
}

int main() {
	static int aa[N], bb[M];
	int n, m, s, i, j;

	srand_();
	scanf("%d%d%d", &n, &m, &s);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	for (j = 0; j < m; j++)
		scanf("%d", &bb[j]);
	printf("%lld\n", count_vertices(aa, n, bb, m, s) - count_edges(aa, n, bb, m, s) + count_faces(aa, n, bb, m, s) - 1);
	return 0;
}

/* Codeforces 1550F - Jumping Around
 * https://codeforces.com/problemset/problem/1550/F
 * rating: 2700 | tags: binary search, data structures, divide and conquer, dp, dsu, graphs, shortest paths
 * source: accepted submission #122481833 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define N	200000
#define INF	0x3f3f3f3f

unsigned int X;

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	X = (tv.tv_sec ^ tv.tv_usec) | 1;
}

int rand_() {
	return (X *= 3) >> 1;
}

int abs_(int a) { return a > 0 ? a : -a; }

int ds[N], ww1[N];

int find(int i) {
	return ds[i] < 0 ? i : find(ds[i]);
}

int join(int i, int j, int w) {
	i = find(i);
	j = find(j);
	if (i == j)
		return 0;
	if (ds[i] > ds[j])
		ds[i] = j, ww1[i] = w;
	else {
		if (ds[i] == ds[j])
			ds[i]--;
		ds[j] = i, ww1[j] = w;
	}
	return 1;
}

int query(int i, int j) {
	int w = 0;

	while (i != j)
		if (ww1[i] < ww1[j])
			w = ww1[i], i = ds[i];
		else
			w = ww1[j], j = ds[j];
	return w;
}

int cc[N], pp[N], qq[N], n, d;

int prev(int i, int c) {
	return i < 0 ? -1 : (cc[i] != c ? i : pp[i]);
}

int next(int i, int c) {
	return i >= n ? n : (cc[i] != c ? i : qq[i]);
}

int uu[N], vv[N], ww[N], xx[N];

void try(int i, int j) {
	int ci = cc[i], u, v, w;

	if (j < 0 || j >= n)
		return;
	w = abs_(abs_(xx[j] - xx[i]) - d);
	if (i < j)
		u = i, v = j;
	else
		u = j, v = i;
	if (ww[ci] > w || ww[ci] == w && (uu[ci] > u || uu[ci] == u && vv[ci] > v))
		ww[ci] = w, uu[ci] = u, vv[ci] = v;
}

int uu_[N - 1], vv_[N - 1], ww_[N - 1];

void sort(int *hh, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, h = hh[l + rand_() % (r - l)], tmp;

		while (j < k)
			if (ww_[hh[j]] == ww_[h])
				j++;
			else if (ww_[hh[j]] < ww_[h]) {
				tmp = hh[i], hh[i] = hh[j], hh[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = hh[j], hh[j] = hh[k], hh[k] = tmp;
			}
		sort(hh, l, i);
		l = k;
	}
}

int main() {
	static int ll[N], rr[N], hh[N - 1];
	int q, s, h, i, j, m;

	srand_();
	scanf("%d%d%d%d", &n, &q, &s, &d), s--;
	for (i = 0; i < n; i++)
		scanf("%d", &xx[i]);
	for (i = 0, j = 0; j < n; j++) {
		while (xx[j] - xx[i] > d)
			i++;
		ll[j] = i;
	}
	for (i = n - 1, j = n - 1; i >= 0; i--) {
		while (xx[j] - xx[i] > d)
			j--;
		rr[i] = j;
	}
	memset(ds, -1, n * sizeof *ds);
	m = 0;
	while (m < n - 1) {
		for (i = 0; i < n; i++) {
			cc[i] = find(i);
			uu[i] = vv[i] = -1, ww[i] = INF;
		}
		for (i = 0; i < n; i++)
			pp[i] = i == 0 || cc[i - 1] != cc[i] ? i - 1 : pp[i - 1];
		for (i = n - 1; i >= 0; i--)
			qq[i] = i == n - 1 || cc[i + 1] != cc[i] ? i + 1 : qq[i + 1];
		for (i = 0; i < n; i++)
			try(i, prev(ll[i] - 1, cc[i])), try(i, next(ll[i], cc[i])), try(i, prev(rr[i], cc[i])), try(i, next(rr[i] + 1, cc[i]));
		for (i = 0; i < n; i++)
			if (ww[i] != INF && join(uu[i], vv[i], ww[i]))
				uu_[m] = uu[i], vv_[m] = vv[i], ww_[m] = ww[i], m++;
	}
	for (h = 0; h < n - 1; h++)
		hh[h] = h;
	sort(hh, 0, n - 1);
	memset(ds, -1, n * sizeof *ds), memset(ww1, 0x3f, n * sizeof *ww1);
	for (h = 0; h < n - 1; h++)
		join(uu_[hh[h]], vv_[hh[h]], ww_[hh[h]]);
	while (q--) {
		int w;

		scanf("%d%d", &i, &w), i--;
		printf(query(s, i) <= w ? "Yes\n" : "No\n");
	}
	return 0;
}

/* Codeforces 1389F - Bicolored Segments
 * https://codeforces.com/problemset/problem/1389/F
 * rating: 2600 | tags: data structures, dp, graph matchings, sortings
 * source: accepted submission #88357358 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N	200000

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
	return (rand() * 76543LL + rand()) % n;
}

int xx[N][2], tt[N];

int compare(const void *a, const void *b) {
	int h1 = *(int *) a;
	int h2 = *(int *) b;
	int x1 = xx[h1 >> 1][h1 & 1], x2 = xx[h2 >> 1][h2 & 1];

	return x1 != x2 ? x1 - x2 : (h1 & 1) - (h2 & 1);
}

void sort(int *hh, int n) {
	int h;

	for (h = 0; h < n; h++) {
		int h_ = rand_(h + 1), tmp;

		tmp = hh[h], hh[h] = hh[h_], hh[h_] = tmp;
	}
	qsort(hh, n, sizeof *hh, compare);
}

int iq[2][1 + N], pq[N], cnt[2], mode;

int lt(int i, int j) { return xx[i][1] < xx[j][1]; }

int p2(int p) {
	return (p *= 2) > cnt[mode] ? 0 : p < cnt[mode] && lt(iq[mode][p + 1], iq[mode][p]) ? p + 1 : p;
}

void pq_up(int i) {
	int p, q, j;

	for (p = pq[i]; (q = p / 2) && lt(i, j = iq[mode][q]); p = q)
		iq[mode][pq[j] = p] = j;
	iq[mode][pq[i] = p] = i;
}

void pq_dn(int i) {
	int p, q, j;

	for (p = pq[i]; (q = p2(p)) && lt(j = iq[mode][q], i); p = q)
		iq[mode][pq[j] = p] = j;
	iq[mode][pq[i] = p] = i;
}

void pq_add(int i) {
	pq[i] = ++cnt[mode], pq_up(i);
}

void pq_remove_first() {
	int i = iq[mode][1], j = iq[mode][cnt[mode]--];

	if (j != i)
		pq[j] = 1, pq_dn(j);
	pq[i] = 0;
}

void pq_remove(int i) {
	int j = iq[mode][cnt[mode]--];

	if (j != i)
		pq[j] = pq[i], pq_up(j), pq_dn(j);
	pq[i] = 0;
}

int main() {
	static int hh[N * 2];
	int n, h, i, ans;

	srand_();
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d%d", &xx[i][0], &xx[i][1], &tt[i]), tt[i]--;
	for (h = 0; h < n * 2; h++)
		hh[h] = h;
	sort(hh, n * 2);
	ans = n;
	for (h = 0; h < n * 2; h++) {
		int h_, lr;

		h_ = hh[h], i = h_ >> 1, lr = h_ & 1;
		if (lr == 0)
			mode = tt[i], pq_add(i);
		else if (pq[i]) {
			mode = tt[i], pq_remove(i);
			mode = tt[i] ^ 1;
			if (cnt[mode])
				ans--, pq_remove_first();
		}
	}
	printf("%d\n", ans);
	return 0;
}

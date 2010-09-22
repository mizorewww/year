/* Codeforces 1251E2 - Voting (Hard Version)
 * https://codeforces.com/problemset/problem/1251/E2
 * rating: 2400 | tags: binary search, data structures, greedy
 * source: accepted submission #63332845 (GNU C11) downloaded from Codeforces
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

int mm[N], pp[N];

int pq[1 + N], iq[N], cnt;

int less(int u, int v) {
	return pp[u] > pp[v];
}

int i2(int i) {
	return (i *= 2) > cnt ? 0 : i < cnt && less(pq[i + 1], pq[i]) ? i + 1 : i;
}

void pq_up(int u) {
	int i, j, v;

	for (i = iq[u]; (j = i / 2) && less(u, v = pq[j]); i = j)
		pq[iq[v] = i] = v;
	pq[iq[u] = i] = u;
}

void pq_dn(int u) {
	int i, j, v;

	for (i = iq[u]; (j = i2(i)) && less(v = pq[j], u); i = j)
		pq[iq[v] = i] = v;
	pq[iq[u] = i] = u;
}

void pq_add(int u) {
	iq[u] = ++cnt, pq_up(u);
}

int pq_remove_first() {
	int u = pq[1], v = pq[cnt--];

	if (v != u)
		iq[v] = 1, pq_dn(v);
	return u;
}

int compare(const void *a, const void *b) {
	int i = *(int *) a;
	int j = *(int *) b;

	return mm[i] - mm[j];
}

void sort(int *ii, int n) {
	int i;

	for (i = 0; i < n; i++) {
		int j = rand_(i + 1), tmp;

		tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
	}
	qsort(ii, n, sizeof *ii, compare);
}

int main() {
	int t;

	srand_();
	scanf("%d", &t);
	while (t--) {
		static int ii[N];
		int n, m, i;
		long long ans;

		scanf("%d", &n);
		ans = 0;
		for (i = 0; i < n; i++) {
			scanf("%d%d", &mm[i], &pp[i]);
			ans += pp[i];
			ii[i] = i;
		}
		sort(ii, n);
		cnt = 0;
		for (m = 0, i = 0; m < n; m++) {
			while (i < n && mm[ii[i]] == m)
				pq_add(ii[i++]);
			if (cnt)
				ans -= pp[pq_remove_first()];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

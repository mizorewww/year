/* Codeforces 1401D - Maximum Distributed Tree
 * https://codeforces.com/problemset/problem/1401/D
 * rating: 1800 | tags: dfs and similar, dp, greedy, implementation, math, number theory, sortings, trees
 * source: accepted submission #90587768 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N	100000
#define M	60000
#define MD	1000000007

int min(int a, int b) { return a < b ? a : b; }

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
	return (rand() * 76543LL + rand()) % n;
}

int *oj[N], oo[N];

void link(int i, int j) {
	int o = oo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		oj[i] = (int *) realloc(oj[i], o * 2 * sizeof *oj[i]);
	oj[i][o] = j;
}

int sz[N];

void dfs(int p, int i) {
	int o;

	sz[i] = 1;
	for (o = 0; o < oo[i]; o++) {
		int j = oj[i][o];

		if (j != p) {
			dfs(i, j);
			sz[i] += sz[j];
		}
	}
}

int compare(const void *a, const void *b) {
	int ia = *(int *) a;
	int ib = *(int *) b;

	return ib - ia;
}

int compare_(const void *a, const void *b) {
	int i = *(int *) a;
	int j = *(int *) b;

	return sz[j] - sz[i];
}

void sort(int *aa, int n, int (*cmp)(const void *, const void *)) {
	int i;

	for (i = 0; i < n; i++) {
		int j = rand_(i + 1), tmp;

		tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
	}
	qsort(aa, n, sizeof *aa, cmp);
}

int main() {
	int t;

	srand_();
	scanf("%d", &t);
	while (t--) {
		static int pp[M], ii[N];
		int n, m, h, i, j, ans;

		scanf("%d", &n);
		for (i = 0; i < n; i++)
			oj[i] = (int *) malloc(2 * sizeof *oj[i]), oo[i] = 0;
		for (h = 0; h < n - 1; h++) {
			scanf("%d%d", &i, &j), i--, j--;
			link(i, j), link(j, i);
		}
		scanf("%d", &m);
		for (h = 0; h < m; h++)
			scanf("%d", &pp[h]);
		sort(pp, m, compare);
		dfs(-1, 0);
		for (i = 0; i < n; i++) {
			sz[i] = min(sz[i], n - sz[i]);
			ii[i] = i;
		}
		sort(ii, n, compare_);
		if (m < n - 1) {
			ans = 0;
			for (i = 0; i < n - 1; i++)
				ans = (ans + (long long) sz[ii[i]] * (n - sz[ii[i]]) * (i < m ? pp[i] : 1)) % MD;
		} else {
			ans = (long long) sz[ii[0]] * (n - sz[ii[0]]) % MD;
			for (h = 0; h < m - (n - 2); h++)
				ans = (long long) ans * pp[h] % MD;
			for (i = 1; i < n - 1; i++)
				ans = (ans + (long long) sz[ii[i]] * (n - sz[ii[i]]) * pp[m - n + i + 1]) % MD;
		}
		printf("%d\n", ans);
	}
	return 0;
}

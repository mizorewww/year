/* Codeforces 1527D - MEX Tree
 * https://codeforces.com/problemset/problem/1527/D
 * rating: 2400 | tags: combinatorics, dfs and similar, implementation, math, trees
 * source: accepted submission #116798389 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

#define N	200000
#define LN	17	/* LN = floor(log2(N)) */

int *ej[N], eo[N];

void append(int i, int j) {
	int o = eo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}

int dd[N], pp[N][LN + 1], sz[N], ta[N], tb[N], time;

void dfs(int p, int i, int d) {
	int o, l;

	dd[i] = d;
	pp[i][0] = p;
	for (l = 1; 1 << l <= d; l++)
		pp[i][l] = pp[pp[i][l - 1]][l - 1];
	sz[i] = 1;
	ta[i] = time++;
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		if (j != p) {
			dfs(i, j, d + 1);
			sz[i] += sz[j];
		}
	}
	tb[i] = time;
}

int lca(int i, int j) {
	int tmp, l;

	if (dd[i] < dd[j])
		tmp = i, i = j, j = tmp;
	for (l = LN; l >= 0; l--)
		if (dd[i] - dd[j] >= 1 << l)
			i = pp[i][l];
	if (i == j)
		return i;
	for (l = LN; l >= 0; l--)
		if (dd[i] >= 1 << l && pp[i][l] != pp[j][l])
			i = pp[i][l], j = pp[j][l];
	return pp[i][0];
}

int next(int i, int j) {
	int l;

	for (l = LN; l >= 0; l--)
		if (dd[j] - dd[i] > 1 << l)
			j = pp[j][l];
	return j;
}

int ancestor(int i, int j) {
	return ta[i] <= ta[j] && ta[j] < tb[i];
}

int on_path(int i, int j, int k) {
	return ancestor(k, i) != ancestor(k, j) || k == lca(i, j);
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		static long long ans[N + 1];
		int n, h, i, j, k, o;

		scanf("%d", &n);
		for (i = 0; i < n; i++)
			ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo[i] = 0;
		for (h = 0; h < n - 1; h++) {
			scanf("%d%d", &i, &j);
			append(i, j), append(j, i);
		}
		time = 0, dfs(-1, 0, 0);
		ans[0] = ans[1] = (long long) n * (n - 1) / 2;
		for (o = eo[0]; o--; ) {
			j = ej[0][o];
			ans[1] -= (long long) sz[j] * (sz[j] - 1) / 2;
		}
		i = 0, j = 1;
		for (k = 1; k < n; k++) {
			if (k > 1 && !on_path(i, j, k)) {
				if (on_path(i, k, j))
					j = k;
				else if (on_path(j, k, i))
					i = k;
				else {
					while (k++ < n)
						ans[k] = 0;
					break;
				}
			}
			if (ancestor(i, j))
				ans[k + 1] = (long long) (sz[i] - sz[next(i, j)]) * sz[j];
			else if (ancestor(j, i))
				ans[k + 1] = (long long) (sz[j] - sz[next(j, i)]) * sz[i];
			else
				ans[k + 1] = (long long) sz[i] * sz[j];
		}
		for (k = 0; k < n; k++)
			ans[k] -= ans[k + 1];
		for (k = 0; k <= n; k++)
			printf("%lld ", ans[k]);
		printf("\n");
		for (i = 0; i < n; i++)
			free(ej[i]);
	}
	return 0;
}

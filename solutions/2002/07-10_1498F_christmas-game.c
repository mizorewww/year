/* Codeforces 1498F - Christmas Game
 * https://codeforces.com/problemset/problem/1498/F
 * rating: 2500 | tags: bitmasks, data structures, dfs and similar, dp, games, math, trees
 * source: accepted submission #111366653 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

#define N	100000
#define K	20

int *ej[N], eo[N];

void append(int i, int j) {
	int o = eo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}

int aa[N], dp[N][K * 2], dq[N][K * 2], k;

void dfs1(int p, int i) {
	int o, d;

	dp[i][0] = aa[i];
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		if (j != p) {
			dfs1(i, j);
			for (d = 0; d < k * 2; d++)
				dp[i][d] ^= dp[j][(d - 1 + k * 2) % (k * 2)];
		}
	}
}

void dfs2(int p, int i) {
	int o, d;

	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		if (j != p) {
			for (d = 0; d < k * 2; d++)
				dq[j][d] = dq[i][(d - 1 + k * 2) % (k * 2)] ^ dp[i][(d - 1 + k * 2) % (k * 2)] ^ dp[j][(d - 2 + k * 2) % (k * 2)];
			dfs2(i, j);
		}
	}
}

int main() {
	int n, h, i, j, d;

	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		ej[i] = (int *) malloc(2 * sizeof *ej[i]);
	for (h = 0; h < n - 1; h++) {
		scanf("%d%d", &i, &j), i--, j--;
		append(i, j), append(j, i);
	}
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	dfs1(-1, 0);
	dfs2(-1, 0);
	for (i = 0; i < n; i++) {
		int x;

		x = 0;
		for (d = k; d < k * 2; d++)
			x ^= dp[i][d] ^ dq[i][d];
		printf("%d ", x ? 1 : 0);
	}
	printf("\n");
	return 0;
}

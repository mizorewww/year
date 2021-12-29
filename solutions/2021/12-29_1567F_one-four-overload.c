/* Codeforces 1567F - One-Four Overload
 * https://codeforces.com/problemset/problem/1567/F
 * rating: 2700 | tags: 2-sat, constructive algorithms, dfs and similar, dsu, graphs, implementation
 * source: accepted submission #127949407 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define N	500
#define M	500

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

int main() {
	static char cc[N][M + 1];
	static int aa[N][M];
	int n, m, h, i, j, k;

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", cc[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (cc[i][j] != 'X')
				continue;
			k = 0;
			for (h = 0; h < 4; h++) {
				int i_ = i + di[h], j_ = j + dj[h];

				if (cc[i_][j_] == '.')
					k ^= 1;
			}
			if (k % 2 != 0) {
				printf("NO\n");
				return 0;
			}
		}
	for (i = 0; i < n; i++)
		for (j = 0, k = 0; j < m; j++)
			if (cc[i][j] == '.')
				aa[i][j] = (i + k) % 2 == 0 ? 1 : 4;
			else if (cc[i - 1][j] == 'X')
				k ^= 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (cc[i][j] == 'X')
				for (h = 0; h < 4; h++) {
					int i_ = i + di[h], j_ = j + dj[h];

					if (cc[i_][j_] == '.')
						aa[i][j] += aa[i_][j_];
				}
	printf("YES\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", aa[i][j]);
		printf("\n");
	}
	return 0;
}

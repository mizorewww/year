/* Codeforces 1583C - Omkar and Determination
 * https://codeforces.com/problemset/problem/1583/C
 * rating: 1700 | tags: data structures, dp
 * source: accepted submission #132239797 (GNU C11) downloaded from Codeforces
 */

/*
ID: double_4
LANG: C
TASK:
*/
#include <stdio.h>

//#include <stdlib.h>
//char **a;
char inline gc() {
	char rtn;
	do
		rtn = getchar();
	while (rtn != '.' && rtn != 'X');
	return rtn;
}

int main() {
	int n, m, q;
	int i, j;
	scanf("%d%d", &n, &m);
	char a[n + 2][m + 2];
	int b[m + 2] ;
	for (i = 1; i <= m; ++i)
		b[i] = 0;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j) {
			a[i][j] = gc();
			if (i > 1 && j > 1 && a[i - 1][j] == 'X' && a[i][j - 1] == 'X')
				b[j] = 1;
		}
	for (i = 2; i <= m; ++i)
		b[i] += b[i - 1];
//	for (i = 1; i <= m; ++i)
//		printf("%d ", b[i]);
	scanf("%d", &q);
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y || b[y] == b[x])
			puts("YES");
		else
			puts("NO");

	}
	return 0;
}

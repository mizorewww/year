/* Codeforces 1485D - Multiples and Power Differences
 * https://codeforces.com/problemset/problem/1485/D
 * rating: 2200 | tags: constructive algorithms, graphs, math, number theory
 * source: accepted submission #107216117 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define A	720720

int main() {
	int n, m, i, j;

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			int a;

			scanf("%d", &a);
			printf("%d ", (i + j) % 2 == 0 ? A : A - a * a * a * a);
		}
		printf("\n");
	}
	return 0;
}

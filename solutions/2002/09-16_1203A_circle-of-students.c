/* Codeforces 1203A - Circle of Students
 * https://codeforces.com/problemset/problem/1203/A
 * rating: 1000 | tags: implementation
 * source: accepted submission #58757415 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

#define N 200

int main() {
	int q;

	scanf("%d", &q);
	while (q--) {
		static int pp[N];
		int n, i, yes;

		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &pp[i]);
		yes = 1;
		for (i = 1; i < n; i++) {
			int x;

			x = abs(pp[i] - pp[i - 1]);
			if (x != 1 && x != n - 1) {
				yes = 0;
				break;
			}
		}
		printf(yes ? "YES\n" : "NO\n");
	}
	return 0;
}

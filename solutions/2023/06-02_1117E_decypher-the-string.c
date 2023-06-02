/* Codeforces 1117E - Decypher the String
 * https://codeforces.com/problemset/problem/1117/E
 * rating: 2200 | tags: bitmasks, chinese remainder theorem, constructive algorithms, interactive, math
 * source: accepted submission #50126987 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

#define N	10000

int main() {
	static char aa[N + 1], bb[3][N + 1], cc[3][N + 1], dd[N + 1];
	static int pp[N];
	int n, h, i;

	scanf("%s", aa);
	n = strlen(aa);
	/* 26^3 = 17576 >= N */
	for (i = 0; i < n; i++) {
		bb[0][i] = i % 26 + 'a';
		bb[1][i] = i / 26 % 26 + 'a';
		bb[2][i] = i / 26 / 26 % 26 + 'a';
	}
	for (h = 0; h < 3; h++) {
		printf("? %s\n", bb[h]);
		fflush(stdout);
		scanf("%s", cc[h]);
	}
	for (i = 0; i < n; i++) {
		int a = cc[0][i] - 'a';
		int b = cc[1][i] - 'a';
		int c = cc[2][i] - 'a';

		pp[i] = (c * 26 + b) * 26 + a;
	}
	for (i = 0; i < n; i++)
		dd[pp[i]] = aa[i];
	printf("! %s\n", dd);
	fflush(stdout);
	return 0;
}

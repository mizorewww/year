/* Codeforces 1B - Spreadsheet
 * https://codeforces.com/problemset/problem/1/B
 * rating: 1600 | tags: implementation, math
 * source: accepted submission #20215070 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>



char s[20], *p;



int r, c, _;



void print(int x) {

	if (x--) print(x / 26), putchar((x % 26) + 'A');

}



int main() {

for (scanf("%d", &_); _; --_) {

	scanf("%s", s);



	if (sscanf(s, "R%dC%d", &r, &c) == 2) print(c), printf("%d\n", r);

	else {

		for (c = 0, p = s; *p >= 'A'; ++p) c = c * 26 + (*p ^ 64);

		printf("R%sC%d\n", p, c);

	}

}

	return 0;

}

/* Codeforces 1196E - Connected Component on a Chessboard
 * https://codeforces.com/problemset/problem/1196/E
 * rating: 1800 | tags: constructive algorithms, implementation
 * source: accepted submission #57688230 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main() {
	long int q;
	long int b;
	long int w;
	long int u;
	long int l;
	long int i;
	long int j;
	
	scanf("%ld", &q);
	while (--q >= 0) {
		scanf("%ld %ld", &b, &w);
		if (b <= 3 * w + 1 && w <= 3 * b + 1) {
			printf("YES\n");
			if (b > w) {
				i = 2;
				u = b - w - 1;
				b = w + w + 1;
			} else {
				i = 3;
				u = w - b - (w > b ? 1 : 0);
				b = b + b + (w > b ? 1 : 0);
			}
			if (u > b / 2) {
				l = 2 * (u - b / 2);
				u = b;
			} else {
				u = u + u;
				l = 0;
			}
			for (j = 0; ++j <= b; ) {
				printf("%ld %ld\n", i, j);
			}
			--i;
			for (j = 2; j <= u; j += 2) {
				printf("%ld %ld\n", i, j);
			}
			i += 2;
			for (j = 2; j <= l; j += 2) {
				printf("%ld %ld\n", i, j);
			}
		} else {
			printf("NO\n");
		}
	}
}

/* Codeforces 1296B - Food Buying
 * https://codeforces.com/problemset/problem/1296/B
 * rating: 900 | tags: math
 * source: accepted submission #70287755 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int s;

		scanf("%d", &s);
		printf("%d\n", s / 9 * 10 + (s % 9 == 0 ? -1 : s % 9));
	}
	return 0;
}

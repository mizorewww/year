/* Codeforces 1013A - Piles With Stones
 * https://codeforces.com/problemset/problem/1013/A
 * rating: 800 | tags: math
 * source: accepted submission #40951192 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main() {
	int n, p, x, y, cnt[1001] = {0, }, i;
	x = y = 0;
	scanf("%d", &n);
	for (i = 0 ; i < n ; i++) scanf("%d", &p), x += p;
	for (i = 0 ; i < n ; i++) scanf("%d", &p), y += p;
	printf("%s", x >= y ? "Yes" : "No");
}

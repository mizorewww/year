/* Codeforces 1644E - Expand the Path
 * https://codeforces.com/problemset/problem/1644/E
 * rating: 1900 | tags: brute force, combinatorics, data structures, implementation, math
 * source: accepted submission #147343563 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

char s[(int)2e5 + 3];

void test() {
	
	int n;
	scanf("%d", &n);
	scanf("%s", &s[0]);
	int mx = 1;
	int my = 1;
	int x = 1;
	int y = 1;
	for (char* c = &s[0]; *c != '\0'; c++) {
		if (*c == 'D') {
			my++;
		} else {
			mx++;
		}
	}
	long long ans = (long long) n * n;
	for (char* c = &s[0]; *c != '\0'; c++) {
		//if (*(c + 1) != '\0' && *c == *(c + 1)) {
			//continue;
		//}
		if (*c == 'D') {
			if (x > 1) {
				int right = mx - x;
				ans -= right;
			} else {
				int right = n - x;
				ans -= right;
			}
			y++;
		} else {
			if (y > 1) {
				int down = my - y;
				ans -= down;
			} else {
				int down = n - y;
				ans -= down;
			}
			x++;
		}
	}
	if (x == 1 || y == 1) {
		printf("%d\n", n);
		return;
	}
	printf("%lld\n", ans);
	
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		test();
	}
}

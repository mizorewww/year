/* Codeforces 878A - Short Program
 * https://codeforces.com/problemset/problem/878/A
 * rating: 1600 | tags: bitmasks, constructive algorithms
 * source: accepted submission #31755574 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main(void) {
	int n;
	int a, b;

	scanf("%d", &n);
	a = 0;
	b = 1023;
	for (int i = 0; i < n; i++) {
		char op;
		int x;

		scanf(" %c %d", &op, &x);

		switch (op) {
			case '|':
				a |= x;
				b |= x;
				break;
			case '^':
				a ^= x;
				b ^= x;
				break;
			case '&':
				a &= x;
				b &= x;
				break;
		}
	}

	int s[3] = {0};
	for (int i = 0; i < 10; i++) {
		const int aa = a >> i & 1, bb = b >> i & 1;
		if (aa == 0 && bb == 0) {
			s[0] |= 0 << i;
			s[1] |= 0 << i;
			s[2] |= 0 << i;
		} else if (aa == 0 && bb == 1) {
			s[0] |= 0 << i;
			s[1] |= 0 << i;
			s[2] |= 1 << i;
		} else if (aa == 1 && bb == 0) {
			s[0] |= 0 << i;
			s[1] |= 1 << i;
			s[2] |= 1 << i;
		} else {
			s[0] |= 1 << i;
			s[1] |= 0 << i;
			s[2] |= 1 << i;
		}
	}

	puts("3");
	printf("| %d\n", s[0]);
	printf("^ %d\n", s[1]);
	printf("& %d\n", s[2]);

	return 0;
}

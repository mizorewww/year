/* Codeforces 1230B - Ania and Minimizing
 * https://codeforces.com/problemset/problem/1230/B
 * rating: 1000 | tags: greedy, implementation
 * source: accepted submission #61158391 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define N	200000

int main() {
	static char cc[N + 1];
	int n, k, i;

	scanf("%d%d%s", &n, &k, cc);
	for (i = 0; i < n && k > 0; i++) {
		int d = n == 1 || i >= 1 ? 0 : 1;

		if (cc[i] != d + '0') {
			cc[i] = d + '0';
			k--;
		}
	}
	printf("%s\n", cc);
	return 0;
}

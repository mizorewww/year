/* Codeforces 1514C - Product 1 Modulo N
 * https://codeforces.com/problemset/problem/1514/C
 * rating: 1600 | tags: greedy, number theory
 * source: accepted submission #113526106 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define N	100000

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	static char used[N];
	int n, m, a, x;

	scanf("%d", &n);
	m = 0, x = 1;
	for (a = 1; a < n; a++)
		if (gcd(n, a) == 1) {
			used[a] = 1, m++;
			x = (long long) x * a % n;
		}
	if (x != 1)
		used[x] = 0, m--;
	printf("%d\n", m);
	for (a = 1; a < n; a++)
		if (used[a])
			printf("%d ", a);
	printf("\n");
	return 0;
}

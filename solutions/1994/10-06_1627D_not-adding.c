/* Codeforces 1627D - Not Adding
 * https://codeforces.com/problemset/problem/1627/D
 * rating: 1900 | tags: brute force, dp, math, number theory
 * source: accepted submission #142865768 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define A	1000000

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	static int dd[A + 1];
	int n, i, a, b, cnt;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		dd[a] = a;
	}
	for (a = 1; a <= A; a++)
		for (b = a; b <= A; b += a)
			dd[a] = gcd(dd[a], dd[b]);
	cnt = 0;
	for (a = 1; a <= A; a++)
		if (dd[a] == a)
			cnt++;
	printf("%d\n", cnt - n);
	return 0;
}

/* Codeforces 1389E - Calendar Ambiguity
 * https://codeforces.com/problemset/problem/1389/E
 * rating: 2200 | tags: math, number theory
 * source: accepted submission #88359990 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int m, d, w, n;

		scanf("%d%d%d", &m, &d, &w);
		n = min(m, d);
		w /= gcd(w, d - 1);
		printf("%lld\n", (long long) n % w * (n / w + 1) * (n / w) / 2 + (long long) (w - n % w) * (n / w) * (n / w - 1) / 2);
	}
	return 0;
}

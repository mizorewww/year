/* Codeforces 1623D - Robot Cleaner Revisit
 * https://codeforces.com/problemset/problem/1623/D
 * rating: 2300 | tags: implementation, math, probabilities
 * source: accepted submission #140937611 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

#define NM	100000
#define MD	1000000007

int inv(int a) {
	return a == 1 ? 1 : (long long) inv(a - MD % a) * (MD / a + 1) % MD;
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		static char can[NM * 2];
		int n, m, nm, h, i1, j1, i2, j2, di, dj, p, a, b;

		scanf("%d%d%d%d%d%d%d", &n, &m, &i1, &j1, &i2, &j2, &p), i1--, j1--, i2--, j2--;
		nm = (n - 1) * (m - 1) * 2, p = (long long) (100 - p) * inv(100) % MD;
		memset(can, 0, nm * sizeof *can);
		di = dj = 1;
		for (h = 0; h < nm; h++) {
			if (i1 == i2 || j1 == j2)
				can[h] = 1;
			if (i1 + di < 0 || i1 + di >= n)
				di = -di;
			if (j1 + dj < 0 || j1 + dj >= m)
				dj = -dj;
			i1 += di, j1 += dj;
		}
		a = 1, b = 0;
		for (h = nm - 1; h >= 0; h--) {
			b = (b + 1) % MD;
			if (can[h])
				a = (long long) a * p % MD, b = (long long) b * p % MD;
		}
		printf("%lld\n", (long long) b * inv((MD + 1 - a) % MD) % MD);
	}
	return 0;
}

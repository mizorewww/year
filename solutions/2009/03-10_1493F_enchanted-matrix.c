/* Codeforces 1493F - Enchanted Matrix
 * https://codeforces.com/problemset/problem/1493/F
 * rating: 2600 | tags: bitmasks, interactive, number theory
 * source: accepted submission #109246531 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int query(int n, int m, int i1, int j1, int i2, int j2) {
	int t;

	printf("? %d %d %d %d %d %d\n", n, m, i1 + 1, j1 + 1, i2 + 1, j2 + 1), fflush(stdout);
	scanf("%d", &t);
	return t;
}

int count(int n) {
	int p, cnt;

	cnt = 1;
	for (p = 2; p <= n / p; p++)
		if (n % p == 0) {
			int e;

			e = 0;
			while (n % p == 0)
				n /= p, e++;
			cnt *= e + 1;
		}
	if (n > 1)
		cnt *= 2;
	return cnt;
}

int main() {
	int n1, m1, n, m, p, l, n_, m_, done;

	scanf("%d%d", &n, &m), n1 = n, m1 = m;
	n_ = n;
	for (p = 2; p <= n / p; p++)
		if (n % p == 0) {
			done = 0;
			while (n % p == 0) {
				n /= p;
				if (!done) {
					for (l = 0; 1 << l < p; l++)
						if (1 << l + 1 <= p) {
							if (!query((n_ / p) << l, m1, 0, 0, (n_ / p) << l, 0)) {
								done = 1;
								break;
							}
						} else {
							if (!query(n_ - ((n_ / p) << l), m1, 0, 0, (n_ / p) << l, 0)) {
								done = 1;
								break;
							}
						}
					if (!done)
						n_ /= p;
				}
			}
		}
	if (n > 1) {
		p = n;
		done = 0;
		for (l = 0; 1 << l < p; l++)
			if (1 << l + 1 <= p) {
				if (!query((n_ / p) << l, m1, 0, 0, (n_ / p) << l, 0)) {
					done = 1;
					break;
				}
			} else {
				if (!query(n_ - ((n_ / p) << l), m1, 0, 0, (n_ / p) << l, 0)) {
					done = 1;
					break;
				}
			}
		if (!done)
			n_ /= p;
	}
	m_ = m;
	for (p = 2; p <= m / p; p++)
		if (m % p == 0) {
			done = 0;
			while (m % p == 0) {
				m /= p;
				if (!done) {
					for (l = 0; 1 << l < p; l++)
						if (1 << l + 1 <= p) {
							if (!query(n1, (m_ / p) << l, 0, 0, 0, (m_ / p) << l)) {
								done = 1;
								break;
							}
						} else {
							if (!query(n1, m_ - ((m_ / p) << l), 0, 0, 0, (m_ / p) << l)) {
								done = 1;
								break;
							}
						}
					if (!done)
						m_ /= p;
				}
			}
		}
	if (m > 1) {
		p = m;
		done = 0;
		for (l = 0; 1 << l < p; l++)
			if (1 << l + 1 <= p) {
				if (!query(n1, (m_ / p) << l, 0, 0, 0, (m_ / p) << l)) {
					done = 1;
					break;
				}
			} else {
				if (!query(n1, m_ - ((m_ / p) << l), 0, 0, 0, (m_ / p) << l)) {
					done = 1;
					break;
				}
			}
		if (!done)
			m_ /= p;
	}
	printf("! %d\n", count(n1 / n_) * count(m1 / m_)), fflush(stdout);
	return 0;
}

/* Codeforces 1450H2 - Multithreading (Hard Version)
 * https://codeforces.com/problemset/problem/1450/H2
 * rating: 3300 | tags: combinatorics, implementation, math
 * source: accepted submission #100572613 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define N	200000
#define MD	998244353
#define V2	499122177

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int abs_(int x) { return x > 0 ? x : -x; }

int vv[N + 1], ff[N + 1], gg[N + 1], ip2[N + 1];

void init() {
	int i;

	ff[0] = gg[0] = ip2[0] = 1;
	for (i = 1; i <= N; i++) {
		vv[i] = i == 1 ? 1 : (long long) vv[i - MD % i] * (MD / i + 1) % MD;
		ff[i] = (long long) ff[i - 1] * i % MD;
		gg[i] = (long long) gg[i - 1] * vv[i] % MD;
		ip2[i] = (long long) ip2[i - 1] * V2 % MD;
	}
}

int ch(int n, int k) {
	return k < 0 || k > n ? 0 : (long long) ff[n] * gg[k] % MD * gg[n - k] % MD;
}

int sum(int n, int l, int r) {
	int i, x;

	x = 0;
	for (i = max(l, 0); i <= min(r, n); i++)
		x = (x + ch(n, i)) % MD;
	return x;
}

long long ans;
int n, kw, kb, kq, kq_, l1, r1, l2, r2, x1, y1, x2, y2;

void wiggle() {	/* maintain x1 = sum(kq_ - 1, l1 - 1, r1), y1 = sum(kq_ - 2, l1 - 2, r1 - 1), x2 = sum(kq_ - 1, l2 - 1, r2), y2 = sum(kq_ - 2, l2 - 2, r2 - 1) */
	while (kq_ < kq) {
		if (l1 - 1 <= r1) {
			x1 = ((long long) x1 * 2 + ch(kq_ - 1, l1 - 2) - ch(kq_ - 1, r1)) % MD;
			y1 = ((long long) y1 * 2 + ch(kq_ - 2, l1 - 3) - ch(kq_ - 2, r1 - 1)) % MD;
		}
		if (l2 - 1 <= r2) {
			x2 = ((long long) x2 * 2 + ch(kq_ - 1, l2 - 2) - ch(kq_ - 1, r2)) % MD;
			y2 = ((long long) y2 * 2 + ch(kq_ - 2, l2 - 3) - ch(kq_ - 2, r2 - 1)) % MD;
		}
		if (kq_++ == 1)
			x1 = sum(kq_ - 1, l1 - 1, r1), y1 = sum(kq_ - 2, l1 - 2, r1 - 1), x2 = sum(kq_ - 1, l2 - 1, r2), y2 = sum(kq_ - 2, l2 - 2, r2 - 1);
	} 
	while (kq_ > kq) {
		kq_--;
		if (l1 - 1 <= r1) {
			x1 = ((long long) x1 - ch(kq_ - 1, l1 - 2) + ch(kq_ - 1, r1)) * V2 % MD;
			y1 = ((long long) y1 - ch(kq_ - 2, l1 - 3) + ch(kq_ - 2, r1 - 1)) * V2 % MD;
		}
		if (l2 - 1 <= r2) {
			x2 = ((long long) x2 - ch(kq_ - 1, l2 - 2) + ch(kq_ - 1, r2)) * V2 % MD;
			y2 = ((long long) y2 - ch(kq_ - 2, l2 - 3) + ch(kq_ - 2, r2 - 1)) * V2 % MD;
		}
	}
	while (l1 > 0) {
		l1--;
		if (l1 - 1 <= r1) {
			x1 = (x1 + ch(kq_ - 1, l1 - 1)) % MD;
			y1 = (y1 + ch(kq_ - 2, l1 - 2)) % MD;
		}
	}
	while (l1 <= kq_ && (kw + l1) % 2 != n / 2 % 2) {
		if (l1 - 1 <= r1) {
			x1 = (x1 - ch(kq_ - 1, l1 - 1)) % MD;
			y1 = (y1 - ch(kq_ - 2, l1 - 2)) % MD;
		}
		l1++;
	}
	while (r1 < kq_ && kw - kb + (r1 + 1) * 2 - kq_ < 0) {
		r1++;
		if (l1 - 1 <= r1) {
			x1 = (x1 + ch(kq_ - 1, r1)) % MD;
			y1 = (y1 + ch(kq_ - 2, r1 - 1)) % MD;
		}
	}
	while (r1 >= 0 && (r1 > kq_ || kw - kb + r1 * 2 - kq_ >= 0 || (kw + r1) % 2 != n / 2 % 2)) {
		if (l1 - 1 <= r1) {
			x1 = (x1 - ch(kq_ - 1, r1)) % MD;
			y1 = (y1 - ch(kq_ - 2, r1 - 1)) % MD;
		}
		r1--;
	}
	while (l2 > 0 && kw - kb + (l2 - 1) * 2 - kq_ >= 0) {
		l2--;
		if (l2 - 1 <= r2) {
			x2 = (x2 + ch(kq_ - 1, l2 - 1)) % MD;
			y2 = (y2 + ch(kq_ - 2, l2 - 2)) % MD;
		}
	}
	while (l2 <= kq_ && (kw - kb + l2 * 2 - kq_ < 0 || (kw + l2) % 2 != n / 2 % 2)) {
		if (l2 - 1 <= r2) {
			x2 = (x2 - ch(kq_ - 1, l2 - 1)) % MD;
			y2 = (y2 - ch(kq_ - 2, l2 - 2)) % MD;
		}
		l2++;
	}
	while (r2 < kq_) {
		r2++;
		if (l2 - 1 <= r2) {
			x2 = (x2 + ch(kq_ - 1, r2)) % MD;
			y2 = (y2 + ch(kq_ - 2, r2 - 1)) % MD;
		}
	}
	while (r2 >= 0 && (r2 > kq_ || (kw + r2) % 2 != n / 2 % 2)) {
		if (l2 - 1 <= r2) {
			x2 = (x2 - ch(kq_ - 1, r2)) % MD;
			y2 = (y2 - ch(kq_ - 2, r2 - 1)) % MD;
		}
		r2--;
	}
}

int main() {
	static char cc[N + 1];
	int q, i, ans;

	init();
	scanf("%d%d%s", &n, &q, cc);
	for (i = 0; i < n; i++) {
		if (i % 2 == 1)
			cc[i] = cc[i] == '?' ? '?' : (cc[i] == 'w' ? 'b' : 'w');
		if (cc[i] == 'w')
			kw++;
		else if (cc[i] == 'b')
			kb++;
		else
			kq++;
	}
	l1 = 0, r1 = -2, l2 = 0, r2 = -2;
	wiggle();
	if (kq == 1)
		ans = abs_(kw % 2 == n / 2 % 2 ? (kw - kb - 1) / 4 : (kw - kb + 1) / 4);
	else {
		ans = 0;
		ans = (ans + (long long) x1 * (kq - kw + kb) - (long long) y1 * kq * 2) % MD;
		ans = (ans + (long long) x2 * (kw - kb - kq) + (long long) y2 * kq * 2) % MD;
		ans = (long long) ans * ip2[kq - 1] % MD * ip2[2] % MD;
	}
	if (ans < 0)
		ans += MD;
	printf("%d\n", ans);
	while (q--) {
		static char s[2];
		char c;

		scanf("%d%s", &i, s), i--, c = s[0];
		if (i % 2 == 1)
			c = c == '?' ? '?' : (c == 'w' ? 'b' : 'w');
		if (cc[i] == 'w')
			kw--;
		else if (cc[i] == 'b')
			kb--;
		else
			kq--;
		cc[i] = c;
		if (cc[i] == 'w')
			kw++;
		else if (cc[i] == 'b')
			kb++;
		else
			kq++;
		wiggle();
		if (kq == 1)
			ans = abs_(kw % 2 == n / 2 % 2 ? (kw - kb - 1) / 4 : (kw - kb + 1) / 4);
		else {
			ans = 0;
			ans = (ans + (long long) x1 * (kq - kw + kb) - (long long) y1 * kq * 2) % MD;
			ans = (ans + (long long) x2 * (kw - kb - kq) + (long long) y2 * kq * 2) % MD;
			ans = (long long) ans * ip2[kq - 1] % MD * ip2[2] % MD;
		}
		if (ans < 0)
			ans += MD;
		printf("%d\n", ans);
	}
	return 0;
}

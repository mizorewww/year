/* Codeforces 1117C - Magic Ship
 * https://codeforces.com/problemset/problem/1117/C
 * rating: 1900 | tags: binary search
 * source: accepted submission #50119826 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define N	100000

int all(char *cc, int n, char c) {
	int i;

	for (i = 0; i < n; i++)
		if (cc[i] != c)
			return 0;
	return 1;
}

long long abs_(long long a) { return a < 0 ? -a : a; }

int main() {
	static char cc[N + 1];
	int n, x1, y1, x2, y2, x, y, i;
	long long lower, upper, d;

	scanf("%d%d%d%d%d%s", &x1, &y1, &x2, &y2, &n, cc);
	if (all(cc, n, 'R')) {
		y = abs_(y1 - y2);
		if (x2 - x1 >= y)
			printf("%d\n", y + (x2 - x1 - y + 1) / 2);
		else
			printf("-1\n");
		return 0;
	}
	if (all(cc, n, 'L')) {
		y = abs_(y1 - y2);
		if (x1 - x2 >= y)
			printf("%d\n", y + (x1 - x2 - y + 1) / 2);
		else
			printf("-1\n");
		return 0;
	}
	if (all(cc, n, 'U')) {
		x = abs_(x1 - x2);
		if (y2 - y1 >= x)
			printf("%d\n", x + (y2 - y1 - x + 1) / 2);
		else
			printf("-1\n");
		return 0;
	}
	if (all(cc, n, 'D')) {
		x = abs_(x1 - x2);
		if (y1 - y2 >= x)
			printf("%d\n", x + (y1 - y2 - x + 1) / 2);
		else
			printf("-1\n");
		return 0;
	}
	x = y = 0;
	for (i = 0; i < n; i++)
		if (cc[i] == 'R')
			x++;
		else if (cc[i] == 'L')
			x--;
		else if (cc[i] == 'U')
			y++;
		else
			y--;
	lower = 0, upper = 1LL << 61;
	while (upper - lower > 1) {
		long long x_, y_;

		d = (lower + upper) / 2;
		x_ = x1 + d / n * x;
		y_ = y1 + d / n * y;
		for (i = 0; i < d % n; i++)
			if (cc[i] == 'R')
				x_++;
			else if (cc[i] == 'L')
				x_--;
			else if (cc[i] == 'U')
				y_++;
			else
				y_--;
		if (abs_(x_ - x2) + abs_(y_ - y2) <= d)
			upper = d;
		else
			lower = d;
	}
	printf("%lld\n", upper);
	return 0;
}

/* Codeforces 1107G - Vasya and Maximum Profit
 * https://codeforces.com/problemset/problem/1107/G
 * rating: 2400 | tags: binary search, constructive algorithms, data structures, dp, dsu
 * source: accepted submission #49019239 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N	300000

int gg[N];

int compare(const void *a, const void *b) {
	int i = *(int *) a;
	int j = *(int *) b;

	return gg[i] - gg[j];
}

int dsu[N];
long long pp[N], qq[N], sum[N];

int find(int i) {
	return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
}

long long join(int i, int j) {
	long long x, y;
	int k;

	i = find(i);
	j = find(j);
	if (i == j)
		return 0;
	if (dsu[i] > dsu[j])
		dsu[i] = k = j;
	else {
		if (dsu[i] == dsu[j])
			dsu[i]--;
		dsu[j] = k = i;
	}
	x = qq[i] + pp[j];
	y = pp[i];
	if (y < sum[i] + pp[j])
		y = sum[i] + pp[j];
	pp[k] = y;
	y = qq[j];
	if (y < qq[i] + sum[j])
		y = qq[i] + sum[j];
	qq[k] = y;
	sum[k] = sum[i] + sum[j];
	return x;
}

int main() {
	static int cc[N], dd[N], ii[N];
	int n, a, h, i, j;
	long long ans;

	srand(time(NULL));
	scanf("%d%d", &n, &a);
	ans = 0;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &dd[i], &cc[i]);
		cc[i] = a - cc[i];
		if (ans < cc[i])
			ans = cc[i];
	}
	for (h = 0; h < n - 1; h++) {
		gg[h] = dd[h + 1] - dd[h];
		ii[h] = h;
	}
	for (j = n - 2; j >= 0; j--) {
		int tmp;

		i = rand() % (j + 1);
		tmp = ii[i]; ii[i] = ii[j]; ii[j] = tmp;
	}
	qsort(ii, n - 1, sizeof *ii, compare);
	memset(dsu, -1, sizeof dsu);
	for (i = 0; i < n; i++)
		sum[i] = pp[i] = qq[i] = cc[i];
	for (h = 0; h < n - 1; h++) {
		long long x = join(ii[h], ii[h] + 1), y = gg[ii[h]];

		if (ans < x - y * y)
			ans = x - y * y;
	}
	printf("%lld\n", ans);
	return 0;
}

/* Codeforces 1285E - Delete a Segment
 * https://codeforces.com/problemset/problem/1285/E
 * rating: 2300 | tags: brute force, constructive algorithms, data structures, dp, graphs, sortings, trees, two pointers
 * source: accepted submission #68541992 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define GETA INT64_C(10000000000)

int asumikana(const void* x, const void* y) {
	int64_t a = *(const int64_t*)x, b = *(const int64_t*)y;
	return a < b ? -1 : a > b;
}

int n;
int64_t l[333333], r[333333];

int zaatuCount;
int64_t zaatu[777777];

int zaatuGet(int64_t target) {
	int l = 0, r = zaatuCount - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (zaatu[m] == target) return m;
		else if (zaatu[m] < target) l = m + 1;
		else r = m - 1;
	}
	exit(2);
	return 0;
}

int mareitaso[777777];
int kiriPoint[777777];
int kesiPoint[777777];

int main(void) {
	int t, tomatu;
	if (scanf("%d", &t) != 1) return 1;
	for (tomatu = 0; tomatu < t; tomatu++) {
		int i;
		int syoki = 1;
		int deltaMax = -999;
		if (scanf("%d", &n) != 1) return 1;
		for (i = 0; i < n; i++) {
			int eru, aaru;
			if (scanf("%d%d", &eru, &aaru) != 2) return 1;
			l[i] = ((int64_t)eru + GETA) * 2;
			r[i] = ((int64_t)aaru + GETA) * 2 + 1;
			zaatu[i * 2] = l[i];
			zaatu[i * 2 + 1] = r[i];
		}
		qsort(zaatu, n * 2, sizeof(*zaatu), asumikana);
		zaatuCount = 1;
		for (i = 1; i < n * 2; i++) {
			if (zaatu[zaatuCount - 1] != zaatu[i]) zaatu[zaatuCount++] = zaatu[i];
		}
		memset(mareitaso, 0, sizeof(*mareitaso) * (zaatuCount + 10));
		for (i = 0; i < n; i++) {
			mareitaso[zaatuGet(l[i]) + 1]++;
			mareitaso[zaatuGet(r[i]) + 1]--;
		}
		for (i = 1; i <= zaatuCount; i++) mareitaso[i] += mareitaso[i - 1];
#if 0
		for(i = 0; i <= zaatuCount; i++) printf(" %d", mareitaso[i]);
		puts("");
#endif
		for (i = 1; i <= zaatuCount; i++) {
			kiriPoint[i] = kiriPoint[i - 1];
			kesiPoint[i] = kesiPoint[i - 1];
			if (mareitaso[i] == 1 && mareitaso[i - 1] >= 1 && mareitaso[i + 1] >= 1) kiriPoint[i]++;
			if (mareitaso[i] == 1 && mareitaso[i - 1] == 0 && mareitaso[i + 1] == 0) kesiPoint[i]++;
			if (mareitaso[i] == 0 && mareitaso[i - 1] >= 1 && mareitaso[i + 1] >= 1) syoki++;
		}
		for (i = 0; i < n; i++) {
			/* zaatuGet(hoge) + 1 - 1 */
			int kiriCount = kiriPoint[zaatuGet(r[i])] - kiriPoint[zaatuGet(l[i])];
			int kesiCount = kesiPoint[zaatuGet(r[i])] - kesiPoint[zaatuGet(l[i])];
			int delta = kiriCount - kesiCount;
			if (delta > deltaMax) deltaMax = delta;
		}
		printf("%d\n", syoki + deltaMax);
	}
	return 0;
}

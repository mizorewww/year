/* Codeforces 1257F - Make Them Similar
 * https://codeforces.com/problemset/problem/1257/F
 * rating: 2400 | tags: bitmasks, brute force, hashing, meet-in-the-middle
 * source: accepted submission #64836652 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N	100
#define MD	0x7fffffff
#define M	(1 << 15)

int count(int x) {
	return x == 0 ? 0 : count(x & x - 1) + 1;
}

int X, Y;

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srand(tv.tv_sec ^ tv.tv_usec);
	X = (rand() * 76543LL + rand()) % (MD - 100) + 100;
	Y = (rand() * 76543LL + rand()) % (MD - 100) + 100;
}

long long hash(int *aa, int n) {
	int x, y, i;

	x = y = 1;
	for (i = 0; i < n; i++) {
		x = ((long long) x * X + aa[i]) % MD;
		y = ((long long) y * Y + aa[i]) % MD;
	}
	return (long long) x * MD + y;
}

int oo[1 + M], val[1 + M]; long long key[1 + M];

int link(int o, long long k, int v) {
	static int _ = 1;

	oo[_] = o, key[_] = k, val[_] = v;
	return _++;
}

int ht[M];

void put(long long k, int v) {
	int h = k % M, o;

	for (o = ht[h]; o; o = oo[o])
		if (key[o] == k) {
			val[o] = v;
			return;
		}
	ht[h] = link(ht[h], k, v);
}

int get(long long k) {
	int h = k % M, o;

	for (o = ht[h]; o; o = oo[o])
		if (key[o] == k)
			return val[o];
	return -1;
}

int main() {
	static int aa[N], bb[N];
	int n, i, x, y;

	srand_();
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	for (x = 0; x < M; x++) {
		for (i = 0; i < n; i++)
			bb[i] = count(x ^ (aa[i] >> 15));
		for (i = 1; i < n; i++)
			bb[i] -= bb[0];
		bb[0] = 0;
		put(hash(bb, n), x);
	}
	for (y = 0; y < M; y++) {
		for (i = 0; i < n; i++)
			bb[i] = count(y ^ (aa[i] & M - 1));
		for (i = 1; i < n; i++)
			bb[i] = bb[0] - bb[i];
		bb[0] = 0;
		if ((x = get(hash(bb, n))) != -1) {
			printf("%d\n", x * M + y);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}

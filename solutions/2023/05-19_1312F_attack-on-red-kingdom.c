/* Codeforces 1312F - Attack on Red Kingdom
 * https://codeforces.com/problemset/problem/1312/F
 * rating: 2500 | tags: games, two pointers
 * source: accepted submission #72835455 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N	300000
#define M	10000
#define X	5
#define Y	5
#define Z	5
#define MD	0x7fffffff

long long max(long long a, long long b) { return a > b ? a : b; }

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srand(tv.tv_sec ^ tv.tv_usec);
}

int rand_(int n) {
	return (rand() * 76543LL + rand()) % n;
}

int oo[1 + M], ok[1 + M], ov[1 + M], _;

int link(int o, int k, int v) {
	oo[_] = o, ok[_] = k, ov[_] = v;
	return _++;
}

int ht[M], X_;

int hash(int k) {
	return (long long) k * X_ % MD % M;
}

void ht_put(int k, int v) {
	int h = hash(k), o;

	for (o = ht[h]; o; o = oo[o])
		if (ok[o] == k) {
			ov[o] = v;
			return;
		}
	ht[h] = link(ht[h], k, v);
}

int ht_get(int k, int v) {
	int h = hash(k), o;

	for (o = ht[h]; o; o = oo[o])
		if (ok[o] == k)
			return ov[o];
	return v;
}

int *bb[X + 1][Y + 1][Z + 1], pp[X + 1][Y + 1][Z + 1], cc[X + 1][Y + 1][Z + 1];

int mex(int a, int b, int c) {
	int d = 0;

	while (a == d || b == d || c == d)
		d++;
	return d;
}

void init() {
	int x, y, z, i;

	srand_();
	X_ = rand_(MD >> 1) + (MD >> 1);
	for (x = 1; x <= 5; x++)
		for (y = 1; y <= 5; y++)
			for (z = 1; z <= 5; z++) {
				static int qu[M];
				int b, t_, t, cnt;

				memset(ht, 0, sizeof ht), _ = 1;
				b = 0, t = 1, cnt = 0;
				while ((t_ = ht_get(b, 0)) == 0) {
					int c, dx, dy, dz;

					ht_put(b, t++);
					qu[cnt++] = b;
					c = 0, dx = dy = dz = -1;
					for (i = 0; i < x + y + z; i++) {
						int d = b >> i * 2 & 3;

						if (i < x) {
							if (i == 0)
								dx = d;
							else
								c |= d << (i - 1) * 2;
						} else if (i < x + y) {
							if (i == x)
								dy = d;
							else
								c |= d << (i - 1) * 2;
						} else {
							if (i == x + y)
								dz = d;
							else
								c |= d << (i - 1) * 2;
						}
					}
					c |= mex(dx, dy, dz) << (x - 1) * 2
						| mex(dx, dz, -1) << (x + y - 1) * 2
						| mex(dx, dy, -1) << (x + y + z - 1) * 2;
					b = c;
				}
				bb[x][y][z] = (int *) malloc(cnt * sizeof *bb[x][y][z]);
				memcpy(bb[x][y][z], qu, cnt * sizeof *qu);
				cc[x][y][z] = t - t_;
				pp[x][y][z] = cnt - cc[x][y][z];
			}
}

int grundy(int x, int y, int z, long long a, int t) {
	int b = bb[x][y][z][a < pp[x][y][z] ? a : pp[x][y][z] + (a - pp[x][y][z]) % cc[x][y][z]];
	if (t == 0)
		return b >> (x - 1) * 2 & 3;
	if (t == 1)
		return b >> (x + y - 1) * 2 & 3;
	return b >> (x + y + z - 1) * 2 & 3;
}

int main() {
	int t;

	init();
	scanf("%d", &t);
	while (t--) {
		static long long aa[N];
		static int gr[N], grx[N], gry[N], grz[N];
		int n, x, y, z, i, g, ans;

		scanf("%d%d%d%d", &n, &x, &y, &z);
		for (i = 0; i < n; i++)
			scanf("%lld", &aa[i]);
		g = 0;
		for (i = 0; i < n; i++) {
			g ^= gr[i] = grundy(x, y, z, aa[i], 0);
			grx[i] = grundy(x, y, z, max(aa[i] - x, 0), 0);
			gry[i] = grundy(x, y, z, max(aa[i] - y, 0), 1);
			grz[i] = grundy(x, y, z, max(aa[i] - z, 0), 2);
		}
		ans = 0;
		for (i = 0; i < n; i++) {
			if ((g ^ gr[i] ^ grx[i]) == 0)
				ans++;
			if ((g ^ gr[i] ^ gry[i]) == 0)
				ans++;
			if ((g ^ gr[i] ^ grz[i]) == 0)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

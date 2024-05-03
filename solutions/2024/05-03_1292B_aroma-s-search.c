/* Codeforces 1292B - Aroma's Search
 * https://codeforces.com/problemset/problem/1292/B
 * rating: 1700 | tags: brute force, constructive algorithms, geometry, greedy, implementation
 * source: accepted submission #69116203 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <inttypes.h>

#define LIMIT INT64_C(10000000000000000)

int64_t zettaiti(int64_t num) {
	return num < 0 ? -num : num;
}

int main(void) {
	int64_t x0, y0, ax, ay, bx, by;
	int64_t xs, ys, t;
	int node_count;
	int64_t nx[128], ny[128];
	int i;
	int answer = 0;

	if (scanf("%" SCNd64 "%" SCNd64 "%" SCNd64 "%" SCNd64 "%" SCNd64 "%" SCNd64,
		&x0, &y0, &ax, &ay, &bx,&by) != 6) return 1;
	if (scanf("%" SCNd64 "%" SCNd64 "%" SCNd64, &xs, &ys, &t) != 3) return 1;

	nx[0] = x0;
	ny[0] = y0;
	node_count = 1;
	for (;;) {
		nx[node_count] = ax * nx[node_count - 1] + bx;
		ny[node_count] = ay * ny[node_count - 1] + by;
		if (nx[node_count] <= LIMIT + LIMIT && ny[node_count] <= LIMIT + LIMIT) {
			node_count++;
		} else {
			break;
		}
	}

	/* saisyo ni doko ni mukau ka */
	for (i = 0; i < node_count; i++) {
		int64_t icost = zettaiti(xs - nx[i]) + zettaiti(ys - ny[i]);
		if (icost <= t) {
			int c1 = 1, c2 = 1;
			int64_t cost;
			int j;
			for (cost = icost, j = i - 1; j >= 0; j--) {
				cost += zettaiti(nx[j + 1] - nx[j]) + zettaiti(ny[j + 1] - ny[j]);
				if (cost <= t) c1++; else break;
			}
			for (cost = icost, j = i + 1; j < node_count; j++) {
				cost += zettaiti(nx[j - 1] - nx[j]) + zettaiti(ny[j - 1] - ny[j]);
				if (cost <= t) c2++; else break;
			}
			if (answer < c1) answer = c1;
			if (answer < c2) answer = c2;
		}
	}

	printf("%d\n", answer);
	return 0;
}

/*

saisyo ni doko wo mezasuka * dotti ni ikuka

*/

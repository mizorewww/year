/* Codeforces 1098A - Sum in the tree
 * https://codeforces.com/problemset/problem/1098/A
 * rating: 1600 | tags: constructive algorithms, dfs and similar, greedy, trees
 * source: accepted submission #47979853 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

#define N	100000
#define INF	1000000001

int main() {
	static int pp[N], ss[N], min[N];
	int n, i;
	long long sum;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		min[i] = INF;
	for (i = 1; i < n; i++) {
		scanf("%d", &pp[i]);
		pp[i]--;
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &ss[i]);
		if (ss[i] != -1) {
			if (ss[pp[pp[i]]] > ss[i]) {
				printf("-1\n");
				return 0;
			}
			if (min[pp[i]] > ss[i])
				min[pp[i]] = ss[i];
		}
	}
	for (i = 0; i < n; i++)
		if (ss[i] == -1)
			ss[i] = min[i] == INF ? ss[pp[i]] : min[i];
	sum = ss[0];
	for (i = 1; i < n; i++)
		sum += ss[i] - ss[pp[i]];
	printf("%lld\n", sum);
	return 0;
}

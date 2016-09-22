/* Codeforces 1366G - Construct the String
 * https://codeforces.com/problemset/problem/1366/G
 * rating: 2700 | tags: data structures, dp, strings
 * source: accepted submission #83406432 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

#define N	10000
#define M	10000
#define INF	0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

int main() {
	static char aa[N + 1], bb[M + 1];
	static int pp[N + 1], dp[N + 1], dq[N + 1], qu[N + 1], dr[N + 1], ds[N + 1];
	int n, m, i, j, cnt, ans, p;

	scanf("%s%s", aa, bb), n = strlen(aa), m = strlen(bb);
	for (i = 1; i <= n; i++)
		pp[i] = pp[i - 1] + (aa[i - 1] == '.' ? -1 : 1);
	memset(dp, 0x3f, (n + 1) * sizeof *dp), dp[0] = 0;
	for (j = 0; j < m; j++) {
		cnt = 0;
		for (i = 0; i <= n; i++) {
			int r;

			dq[i] = i == 0 || aa[i - 1] != bb[j] ? INF : min(ds[cnt - 1] + pp[i - 1], INF);
			r = dp[i] + pp[i];
			while (cnt && pp[i] <= pp[qu[cnt - 1]])
				r = min(r, dr[--cnt]);
			qu[cnt] = i, dr[cnt] = r, ds[cnt] = min(cnt == 0 ? INF : ds[cnt - 1], r - pp[i] * 2), cnt++;
		}
		memcpy(dp, dq, (n + 1) * sizeof *dq);
	}
	ans = INF, p = INF;
	for (i = n; i >= 0; i--) {
		p = min(p, pp[i]);
		ans = min(ans, dp[i] + pp[i] + pp[n] - p * 2);
	}
	printf("%d\n", ans);
	return 0;
}

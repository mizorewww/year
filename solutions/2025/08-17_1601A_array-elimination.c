/* Codeforces 1601A - Array Elimination
 * https://codeforces.com/problemset/problem/1601/A
 * rating: 1300 | tags: bitmasks, greedy, math, number theory
 * source: accepted submission #132998171 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <math.h>

int a[200007], cnt[37];

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int n, ans = 0;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++){
			scanf("%d", &a[j]);
		}
		for (int j = 0; j <= 29; j++){
			cnt[j] = 0;
		}
		for (int j = 1; j <= n; j++){
			for (int k = 0; k <= 29; k++){
				if (a[j] >> k & 1) cnt[k]++;
			}
		}
		for (int j = 0; j <= 29; j++){
			ans = gcd(ans, cnt[j]);
		}
		if (ans == 0){
			for (int j = 1; j <= n; j++){
				printf("%d ", j);
			}
		} else {
			int t = sqrt(ans);
			for (int j = 1; j <= t; j++){
				if (ans % j == 0) printf("%d ", j);
			}
			for (int j = t - (t * t == ans ? 1 : 0); j >= 1; j--){
				if (ans % j == 0) printf("%d ", ans / j);
			}
		}
		printf("\n");
	}
	return 0;
}

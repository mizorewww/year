/* Codeforces 1326C - Permutation Partitions
 * https://codeforces.com/problemset/problem/1326/C
 * rating: 1300 | tags: combinatorics, greedy, math
 * source: accepted submission #73703205 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
long long n, k, ans1, ans2=1, i, tmp, cnt, a[200010];
int main()
{
	scanf("%lld%lld", &n, &k);
	ans1=k*n+(-k*k+k)/2;
	printf("%lld ", ans1);
	for(i=1;i<=n;i++){
		scanf("%lld", &tmp);
		if(tmp>(n-k)){
			a[++cnt]=i;
		}
	}
	for(i=1;i<k;i++){
		ans2*=(a[i+1]-a[i]);
		ans2%=998244353;
	}
	printf("%lld", ans2);
}

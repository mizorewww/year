/* Codeforces 1305C - Kuroni and Impossible Calculation
 * https://codeforces.com/problemset/problem/1305/C
 * rating: 1600 | tags: brute force, combinatorics, math, number theory
 * source: accepted submission #72348286 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int abs(int a){
	return a<0?-a:a;
}

int a[200000], num[1000];

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		if(num[a[i]%m]){
			puts("0");
			return 0;
		}
		++num[a[i]%m];
	}
	long long res=1;
	for(i=0;i<n;++i){
		for(j=0;j<i;++j){
			res=res*abs(a[i]-a[j])%m;
		}
	}
	printf("%I64d\n", res);
	return 0;
}

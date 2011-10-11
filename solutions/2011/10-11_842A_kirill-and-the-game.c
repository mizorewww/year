/* Codeforces 842A - Kirill And The Game
 * https://codeforces.com/problemset/problem/842/A
 * rating: 1200 | tags: brute force, two pointers
 * source: accepted submission #29870003 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	long long int l,r,x,y,k,i;
	scanf("%lld%lld%lld%lld%lld",&l,&r,&x,&y,&k);
	for(i=x;i<=y;i++){
		if(k*i >= l && k*i<=r)break;
	}
	if(i<=y)printf("YES\n");
	else printf("NO\n");
	return 0;
}

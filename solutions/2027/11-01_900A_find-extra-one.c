/* Codeforces 900A - Find Extra One
 * https://codeforces.com/problemset/problem/900/A
 * rating: 800 | tags: geometry, implementation
 * source: accepted submission #33130978 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int a,b,n,i,A=0,B=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		if(a<0) A++;
		else B++;
	}
	if(A<=1||B<=1) printf("yes");
	else printf("no");
	return 0;
}

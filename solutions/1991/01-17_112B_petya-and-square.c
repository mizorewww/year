/* Codeforces 112B - Petya and Square
 * https://codeforces.com/problemset/problem/112/B
 * rating: 1200 | tags: implementation, math
 * source: accepted submission #659983 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int n,i,j;
	scanf("%d%d%d",&n,&i,&j);
	if((i==n/2||i==n/2+1)&&(j==n/2||j==n/2+1))
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}

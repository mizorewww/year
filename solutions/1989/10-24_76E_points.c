/* Codeforces 76E - Points
 * https://codeforces.com/problemset/problem/76/E
 * rating: 1700 | tags: implementation, math
 * source: accepted submission #378930 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main() {
	int n,x,y,i;
	long long sx1=0,sx2=0,sy1=0,sy2=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d %d",&x,&y);
		sx1+=x,sx2+=(long long)x*x;
		sy1+=y,sy2+=(long long)y*y;
	}
	printf("%I64d\n",sx2*n-sx1*sx1+sy2*n-sy1*sy1);
	return 0;
}

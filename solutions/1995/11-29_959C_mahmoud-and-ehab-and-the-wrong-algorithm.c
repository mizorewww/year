/* Codeforces 959C - Mahmoud and Ehab and the wrong algorithm
 * https://codeforces.com/problemset/problem/959/C
 * rating: 1500 | tags: constructive algorithms, trees
 * source: accepted submission #36927125 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main(){
	
	int n,i,l;
	scanf("%d",&n);
	if(n<=5)printf("-1\n");
	else{
		l=n/2+1;
		for(i=2;i<=l;i++)printf("1 %d\n",i);
		for(;i<=n;i++)printf("2 %d\n",i);
	}
	for(i=2;i<=n;i++)printf("1 %d\n",i);
	
	return 0;
}

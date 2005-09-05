/* Codeforces 426A - Sereja and Mugs
 * https://codeforces.com/problemset/problem/426/A
 * rating: 800 | tags: implementation
 * source: accepted submission #6487062 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int main(){
	long n,s,b,a=-1;;
	scanf("%ld%ld",&n,&s);
	while(n--){
		scanf("%ld",&b);
		s-=b;
		if(b>a)a=b;
	}
	if(s+a>=0)printf("YES");else printf("NO");
	return 0;
}

/* Codeforces 1304A - Two Rabbits
 * https://codeforces.com/problemset/problem/1304/A
 * rating: 800 | tags: math
 * source: accepted submission #71130181 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int t;
	long int x,y,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%ld%ld%ld%d",&x,&y,&a,&b);
		x=y-x;
		a=a+b;
		if(x%a) printf("-1\n");
		else printf("%ld\n",x/a);
	}
}

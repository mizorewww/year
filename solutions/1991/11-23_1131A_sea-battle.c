/* Codeforces 1131A - Sea Battle
 * https://codeforces.com/problemset/problem/1131/A
 * rating: 800 | tags: math
 * source: accepted submission #50360845 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int main(){
	long w1,h1,w2,h2;
	scanf("%ld%ld%ld%ld",&w1,&h1,&w2,&h2);
	long num=w1+2+h1+h1+2+(w1-w2)+h2+h2+w2;
	printf("%ld",num);
}

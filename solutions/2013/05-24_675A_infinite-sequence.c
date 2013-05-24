/* Codeforces 675A - Infinite Sequence
 * https://codeforces.com/problemset/problem/675/A
 * rating: 1100 | tags: math
 * source: accepted submission #17937865 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==b || (c!=0 && (b-a)%c==0 && (b-a)/c>=0))
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}

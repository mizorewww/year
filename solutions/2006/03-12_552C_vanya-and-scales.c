/* Codeforces 552C - Vanya and Scales
 * https://codeforces.com/problemset/problem/552/C
 * rating: 1900 | tags: brute force, dp, greedy, math, meet-in-the-middle, number theory
 * source: accepted submission #11639072 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u w,m;
int main()
{
	scanf("%u%u",&w,&m);
	while(m)
	{
		if(m%w==1)--m;
		if(m%w==w-1)++m;
		if(m%w==0)m/=w;
		else{printf("NO\n");return 0;}
	}
	printf("YES\n");
	return 0;
}

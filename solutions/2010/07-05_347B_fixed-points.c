/* Codeforces 347B - Fixed Points
 * https://codeforces.com/problemset/problem/347/B
 * rating: 1100 | tags: brute force, implementation, math
 * source: accepted submission #4513457 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u p[100000];
int main()
{
	u t=0,T,r,satu=0,dua=0;
	for(scanf("%u",&T);t<T;t++)scanf("%u",p+t);
	for(t=r=0;t<T;t++)
	{
		if(p[t]==t)r++;
		else
		{
			if(p[p[t]]==t)dua=1;
			if(p[p[t]]!=p[t])satu=1;
		}
	}
	if(dua)r+=2;
	else if(satu)r++;
	printf("%u\n",r);
	return 0;
}

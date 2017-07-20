/* Codeforces 550B - Preparing Olympiad
 * https://codeforces.com/problemset/problem/550/B
 * rating: 1400 | tags: bitmasks, brute force
 * source: accepted submission #11422572 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u R,N[22],n,l,r,d;
void F(u min,u max,u sum,u sel,u deep,u new)
{
	if(new&&sel>1&&max-min>=d&&sum>=l&&sum<=r)++R;
	if(deep==n||sum>r)return;
	F(min,max,sum,sel,deep+1,0);
	F(min>N[deep]?N[deep]:min,max<N[deep]?
	N[deep]:max,sum+N[deep],sel+1,deep+1,1);
	return;
}
int main()
{
	u i=-1;
	for(scanf("%u%u%u%u",&n,&l,&r,&d);++i<n;scanf("%u",N+i));
	F(-1,0,0,0,0,0);printf("%u\n",R);
	return 0;
}

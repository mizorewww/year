/* Codeforces 427E - Police Patrol
 * https://codeforces.com/problemset/problem/427/E
 * rating: 2000 | tags: greedy, implementation, math, ternary search
 * source: accepted submission #6531143 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
int D[1000001];
int main()
{
	u n,k,h,i,j,l,r;
	llu L,R,M;
	scanf("%u%u%i",&n,&k,D);
	if(n<2){printf("0\n");return 0;}
	for(h=i=j=l=r=L=R=0;++i<n;j++)
	{
		scanf("%i",D+i);
		if(j==k)j=0;
		if(j==0)l++;
		L+=l*(llu)(D[i]-D[i-1]);
	}
	for(M=L;--i;h++)
	{
		if(h==k)h=0;
		if(h==0)r++;
		R+=r*(llu)(D[i]-D[i-1]);
		L-=l*(llu)(D[i]-D[i-1]);
		j--;
		if(j==0)j=k;
		if(j==k)l--;
		if(R+L<M)M=R+L;
	}
	printf("%I64u\n",M<<1);
	return 0;
}

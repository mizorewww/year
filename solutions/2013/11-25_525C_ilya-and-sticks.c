/* Codeforces 525C - Ilya and Sticks
 * https://codeforces.com/problemset/problem/525/C
 * rating: 1600 | tags: greedy, math, sortings
 * source: accepted submission #10467424 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned u64;
typedef unsigned u;
u N[111111],L[111111];u64 A;
int F(const void*x,const void*y){return*(int*)x-*(int*)y;}
int main()
{
	u n,i,j;
	scanf("%u",&n);
	for(i=j=-1;++i<n;scanf("%u",N+i));
	qsort(N,n,sizeof(u),F);
	while(--n)if(N[n]-N[n-1]<2){L[++j]=N[n-1];if(!--n)break;}
	for(++j,i=-2;(i+=2)<j;)A+=L[i]*(u64)L[i+1];
	printf("%I64u\n",A);
	return 0;
}

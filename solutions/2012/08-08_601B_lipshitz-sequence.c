/* Codeforces 601B - Lipshitz Sequence
 * https://codeforces.com/problemset/problem/601/B
 * rating: 2100 | tags: data structures, math
 * source: accepted submission #14453703 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
u F(u a,u b){return a>b?a-b:b-a;}
u A[111111],B[111111],L[111111],R[111111],S[111111],V[111111];
int main()
{
	u n,q,i=-1,j,k,x,y;llu r;
	for(scanf("%u%u",&n,&q);++i<n;scanf("%u",A+i));
	for(i=0;++i<n;B[i]=F(A[i],A[i-1]));
	S[0]=B[0]=B[n]=-1;V[0]=0;x=1;
	for(i=0;++i<n;)
	{
		k=B[i];
		while(S[--x]<=k);
		L[i]=V[x]+1;
		S[++x]=k;V[x++]=i;
	}
	S[0]=-1;V[0]=n;x=1;
	for(i=n;--i;)
	{
		k=B[i];
		while(S[--x]<k);
		R[i]=V[x]-1;
		S[++x]=k;V[x++]=i;
	}
	while(q--)
	{
		scanf("%u%u",&i,&j);
		--j;r=0llu;
		for(k=i-1;++k<=j;)
		{
			x=L[k];y=R[k];
			if(x<i)x=i;
			if(y>j)y=j;
			r+=B[k]*(llu)(y-k+1)*(llu)(k-x+1);
		}
		printf("%I64u\n",r);
	}
	return 0;
}

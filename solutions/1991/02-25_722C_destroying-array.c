/* Codeforces 722C - Destroying Array
 * https://codeforces.com/problemset/problem/722/C
 * rating: 1600 | tags: data structures, dsu
 * source: accepted submission #21079096 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
u D[111111],A[111111],B[111111],V[111111];
llu W[111111],N[111111];
u par(u n){if(D[n]==n)return n;return D[n]=par(D[n]);}
int main()
{
	u n,i=-1,j,k;llu r=0;
	for(scanf("%u",&n);++i<n;D[i]=i)scanf("%u",A+i);
	for(i=-1;++i<n;--B[i])scanf("%u",B+i);
	for(i=n;i--;)
	{
		V[k=B[i]]=1;W[k]=A[k];
		if(k<n&&V[k+1])
		{
			j=par(k+1);
			D[j]=k;
			W[k]+=W[j];
		}
		if(k&&V[k-1])
		{
			j=par(k-1);
			D[k]=j;
			W[j]+=W[k];
			k=j;
		}
		if(r<W[k])r=W[k];
		N[i]=r;
	}
	for(i=0;++i<=n;)printf("%I64u\n",N[i]);
	return 0;
}

/* Codeforces 757D - Felicity's Big Secret Revealed
 * https://codeforces.com/problemset/problem/757/D
 * rating: 2200 | tags: bitmasks, dp
 * source: accepted submission #23768242 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#define m 1000000007u
typedef unsigned u;
u D[76][1u<<20],S[1u<<20];
char C[76];
u V[76][76];
int main()
{
	u n,i,j,k,N=1u<<20,b,r=0;
	scanf("%u",&n);
	scanf("%s",C);
	for(i=-1;++i<n;)for(j=i-1,k=0;++j<n;)
	{
		k=k<<1|(C[j]=='1');
		V[i][j]=k;
	}
	for(i=-1;++i<=n;)D[i][0]=1;
	for(i=-1;++i<n;)
	{
		for(j=i-1;++j<n;)
		{
			if(!V[i][j])continue;
			if(V[i][j]>20)break;
			b=1u<<(V[i][j]-1);
			for(k=-1;++k<N;)
			if((D[j+1][k|b]+=D[i][k])>=m)D[j+1][k|b]-=m;
		}
	}
	for(i=-1;++i<=n;)
	{
		for(j=1;j<N;j=j<<1|1)
		if((r+=D[i][j])>=m)r-=m;
	}
	printf("%u\n",r);
	return 0;
}

/* Codeforces 621E - Wet Shark and Blocks
 * https://codeforces.com/problemset/problem/621/E
 * rating: 2000 | tags: dp, matrices
 * source: accepted submission #15714346 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#define m 1000000007u
typedef long long unsigned U;
typedef unsigned u;
u X[111],Y[111],*A,*B,*C,W[11],L[111][111],M[111][111],(*N)[111],(*O)[111],(*P)[111];
int main()
{
	u q,e,r,n,i,j,k;
	scanf("%u%u%u%u",&q,&e,&r,&n);
	for(i=-1;++i<q;++W[j])scanf("%u",&j);
	for(i=-1;++i<n;)for(j=-1;++j<10;M[k][i]+=W[j])k=(i*10+j)%n;
	N=M;O=L;*(A=X)=1;B=Y;
	for(;;)
	{
		if(e&1)
		{
			for(i=-1;++i<n;)for(B[i]=0,j=-1;++j<n;)
			{
				B[i]=(B[i]+N[i][j]*(U)A[j])%m;
			}
			C=A;A=B;B=C;
		}
		if(!(e>>=1))break;
		for(i=-1;++i<n;)for(j=-1;++j<n;)for(O[i][j]=0,k=-1;++k<n;)
		O[i][j]=(O[i][j]+N[i][k]*(U)N[k][j])%m;
		P=N;N=O;O=P;
	}
	printf("%u\n",A[r]);
	return 0;
}

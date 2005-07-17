/* Codeforces 601A - The Two Routes
 * https://codeforces.com/problemset/problem/601/A
 * rating: 1600 | tags: graphs, shortest paths
 * source: accepted submission #14449724 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u A[444][444],B[444][444],(*C)[444],D[444],V[444];
int main()
{
	u i,j,k,n,q;
	scanf("%u%u",&n,&q);
	for(i=0;++i<=n;D[i]=-1)for(j=0;++j<=n;)A[i][j]=1;
	while(q--)
	{
		scanf("%u%u",&i,&j);
		A[i][j]=A[j][i]=0;
		B[i][j]=B[j][i]=1;
	}
	if(A[1][n])C=B;
	if(B[1][n])C=A;
	D[1]=0;
	while(1)
	{
		for(i=0,j=k=-1;++i<=n;)if(!V[i]&&D[i]<j)j=D[k=i];
		if(k==-1u)break;
		V[k]=1;
		for(i=0;++i<=n;)if(!V[i]&&C[k][i]&&D[i]>D[k]+1)D[i]=D[k]+1;
	}
	printf("%i\n",D[n]);
	return 0;
}

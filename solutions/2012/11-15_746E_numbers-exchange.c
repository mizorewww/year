/* Codeforces 746E - Numbers Exchange
 * https://codeforces.com/problemset/problem/746/E
 * rating: 1900 | tags: greedy, implementation, math
 * source: accepted submission #23097513 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
u N[222222],X[222222],C[222222],H[222222];
int F(const void*x,const void*y)
{
	if(N[*(u*)x]>N[*(u*)y])return 1;
	if(N[*(u*)x]<N[*(u*)y])return-1;
	return 0;
}
int main()
{
	u n,m,i,o,e,h,os=1,es=2,g=0;
	scanf("%u%u",&n,&m);h=n>>1;
	if(n&1){printf("-1\n");return 0;}
	for(i=-1;++i<n;X[i]=i)scanf("%u",N+i);
	qsort(X,n,sizeof(u),F);
	for(i=o=e=0;++i<n;)if(N[X[i]]==N[X[i-1]])C[X[i]]=1;
	for(i=n;i--;)if(!C[X[i]])
	{
		if(N[X[i]]&1)
		{
			if(o==h)C[X[i]]=1;
			else++o;
		}
		else
		{
			if(e==h)C[X[i]]=1;
			else++e;
		}
		if(!C[X[i]])
		{
			++g;
			if(N[X[i]]<222222)H[N[X[i]]]=1;
		}
	}
	for(i=-1;++i<n;)if(C[X[i]])
	{
		if(e<h)
		{
			while(H[es])es+=2;
			if(es>m){printf("-1\n");return 0;}
			N[X[i]]=es;es+=2;++e;
		}
		else if(o<h)
		{
			while(H[os])os+=2;
			if(os>m){printf("-1\n");return 0;}
			N[X[i]]=os;os+=2;++o;
		}
	}
	printf("%u\n",n-g);
	for(i=-1;++i<n;)printf("%u%c",N[i],"\n "[i+1<n]);
	return 0;
}

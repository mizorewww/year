/* Codeforces 778A - String Game
 * https://codeforces.com/problemset/problem/778/A
 * rating: 1700 | tags: binary search, greedy, strings
 * source: accepted submission #25039456 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
int F(const void*x,const void*y){return*(int*)x-*(int*)y;}
char A[222222],N[222222];u Ai,Ni;
u S[222222],M[222222];
int main()
{
	scanf("%s%s",A,N);
	for(Ai=-1;A[++Ai];);
	for(Ni=-1;N[++Ni];);
	u i,j,k,lo,hi,mi;
	for(i=-1;++i<Ai;--S[i])scanf("%u",S+i);
	lo=Ni-1;hi=Ai;
	while((mi=(lo+hi)>>1)>lo)
	{
		k=Ai-mi;
		for(j=-1;++j<mi;)M[j]=S[j+k];
		qsort(M,mi,sizeof(u),F);
		for(j=-1,k=0;++j<mi;)
		{
			if(A[M[j]]==N[k])if(++k==Ni)break;
		}
		if(k<Ni)lo=mi;
		else hi=mi;
	}
	printf("%u\n",Ai-hi);
	return 0;
}

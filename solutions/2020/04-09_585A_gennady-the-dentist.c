/* Codeforces 585A - Gennady the Dentist
 * https://codeforces.com/problemset/problem/585/A
 * rating: 1800 | tags: brute force, implementation
 * source: accepted submission #13563087 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u V[4444],P[4444],D[4444],N[4444],A[4444],Ai;
int main()
{
	u n,i,j,E,e;
	scanf("%u",&n);
	for(i=-1;++i<n;N[i]=i+1)scanf("%u%u%u",V+i,D+i,P+i);
	for(j=n;(n=j);)
	{
		A[Ai++]=*N;e=0;E=*V;
		for(i=j=0;++i<n;E=E?E-1:0)
		{
			if(P[i]<e+E){e+=D[i];continue;}
			V[j]=V[i];P[j]=P[i]-e-E;D[j]=D[i];N[j]=N[i];++j;
		}
	}
	printf("%u\n",Ai);
	for(i=-1;++i<Ai;)printf("%u%c",A[i],i+1==Ai?'\n':' ');
	return 0;
}

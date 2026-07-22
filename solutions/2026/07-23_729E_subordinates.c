/* Codeforces 729E - Subordinates
 * https://codeforces.com/problemset/problem/729/E
 * rating: 1900 | tags: constructive algorithms, data structures, graphs, greedy, sortings
 * source: accepted submission #22357364 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
u Z[222222],R[222222],C[222222];
int main()
{
	u n,s,i,k,fz=0,fnz=0,x,a=-1u;
	scanf("%u%u",&n,&s);--s;
	for(i=-1;++i<n;)
	{
		scanf("%u",&k);
		if(!k&&i!=s)++fz;
		else if(i==s&&k)++fnz;
		else ++C[k];
	}
	for(i=0;++i<n;)Z[i]=Z[i-1]+(C[i]==0);
	for(i=n;i--;)R[i]=R[i+1]+C[i+1];
	for(i=0;++i<n;a=a>x?x:a)
	x=fnz+(Z[i]>fz+R[i]?Z[i]:fz+R[i]);
	printf("%u\n",a>n?0:a);
	return 0;
}

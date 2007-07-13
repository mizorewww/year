/* Codeforces 765D - Artsem and Saunders
 * https://codeforces.com/problemset/problem/765/D
 * rating: 1700 | tags: constructive algorithms, dsu, math
 * source: accepted submission #24659719 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u N[111111],H[111111],Hi,G[111111];
int main()
{
	u n,i,k;
	scanf("%u",&n);
	for(i=0;++i<=n;)
	{
		scanf("%u",&k);
		if((N[i]=k)==i)
		{
			H[++Hi]=i;
			G[i]=Hi;
		}
	}
	for(i=0;++i<=n;)
	{
		if(!G[k=N[i]]||H[G[k]]!=k){printf("-1\n");return 0;}
		G[i]=G[k];
	}
	printf("%u\n",Hi);
	for(i=0;++i<=n ;)printf("%u%c",G[i]," \n"[i==n ]);
	for(i=0;++i<=Hi;)printf("%u%c",H[i]," \n"[i==Hi]);
	return 0;
}

/* Codeforces 527B - Error Correct System
 * https://codeforces.com/problemset/problem/527/B
 * rating: 1500 | tags: greedy
 * source: accepted submission #10317001 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u G[33][33];
char S[222222],T[222222];
int main()
{
	u n,h,i,j,k=0;
	scanf("%u%s%s",&n,S,T);
	for(i=-1;++i<n;k+=S[i]!=T[i])G[S[i]-'a'][T[i]-'a']=i+1;
	for(i=-1;++i<26;)for(j=i;++j<26;)if(G[i][j]&&G[j][i])
	{
		printf("%u\n%u %u\n",k-2,G[i][j],G[j][i]);
		return 0;
	}
	for(i=-1;++i<26;)for(j=-1;++j<26;)
	if(j!=i&&G[i][j])for(h=-1;++h<26;)if(h!=i&&G[h][i])
	{
		printf("%u\n%u %u\n",k-1,G[h][i],G[i][j]);
		return 0;
	}
	printf("%u\n-1 -1\n",k);
	return 0;
}

/* Codeforces 1270A - Card Game
 * https://codeforces.com/problemset/problem/1270/A
 * rating: 800 | tags: games, greedy, math
 * source: accepted submission #67904628 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n,k1,k2,flag=0,x;
		scanf("%d %d %d",&n,&k1,&k2);
		for(i=0;i<k1;i++)
		{
			scanf("%d",&x);
			if(x==n)
				flag=1;
		}
		for(i=0;i<k2;i++)
			scanf("%d",&x);
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

/* Codeforces 1234A - Equalize Prices Again
 * https://codeforces.com/problemset/problem/1234/A
 * rating: 800 | tags: math
 * source: accepted submission #61646204 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int t;
		scanf("%d",&t);
		int j=0,sum=0;
		for(int k=0;k<t;k++)
		{
			scanf("%d",&j);
			sum+=j;
		}
		int ans=0;
		ans=sum/t;
		if(sum%t!=0) ans+=1;
		printf("%d\n",ans);
	}
}

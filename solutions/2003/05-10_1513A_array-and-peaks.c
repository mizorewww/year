/* Codeforces 1513A - Array and Peaks
 * https://codeforces.com/problemset/problem/1513/A
 * rating: 800 | tags: constructive algorithms, implementation
 * source: accepted submission #112670995 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n,k,i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(k>(n-1)/2)
		printf("-1");
		else
		{
			int num=1;
			for(i=1;num<=n;i++)
			{
				if(i%2==0&&k!=0)
				{
					printf("%d ",n);
					n--;
					k--;
				}
				else
				{
					printf("%d ",num);
					num++;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

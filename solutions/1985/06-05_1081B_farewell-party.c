/* Codeforces 1081B - Farewell Party
 * https://codeforces.com/problemset/problem/1081/B
 * rating: 1500 | tags: constructive algorithms, implementation
 * source: accepted submission #47115763 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int n,i,color,flag;
int a[100010],b[100010],c[100010],d[100010];
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(c[a[i]]==0)
		{
			color++;
			d[a[i]]=color;
			c[a[i]]=n-a[i]-1;
			b[i]=color;
		}
		else
		{
			c[a[i]]--;
			b[i]=d[a[i]];
		}
	}
	flag=0;
	for(i=0;i<n;i++)if(c[a[i]]>0)flag=1;
	if(flag==1)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("Possible\n");
		for(i=0;i<n;i++)printf("%d ",b[i]);
	}
}

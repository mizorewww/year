/* Codeforces 847A - Union of Doubly Linked Lists
 * https://codeforces.com/problemset/problem/847/A
 * rating: 1500 | tags: implementation
 * source: accepted submission #30472074 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n;
	int a[105]={0};
	int b[105]={0};
	scanf("%d",&n);
	int i=0,count=0;
	int z[105]={0};
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		if(b[i]==0)z[count++]=i;
	}
	int left=0;
	int x=0;
	for(i=0;i<count;i++)
	{
		b[z[i]]=x;
		x = z[i];
		while(a[x]!=0)
		{
			x=a[x];
		}
		if(i+1<count)a[x]=z[i+1];
	}
	for(i=1;i<=n;i++)
	{
		printf("%d %d\n",a[i],b[i]);
	}
	return 0;
}

/* Codeforces 1141B - Maximal Continuous Rest
 * https://codeforces.com/problemset/problem/1141/B
 * rating: 900 | tags: implementation
 * source: accepted submission #51522132 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int i,n,a[200000],c=0,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]==1)c++;
		else
		{
			if(max<=c)max=c;
			c=0;
		}
	}
	if(a[n-1]==1)
	{
		for(i=0;a[i]==1;i++)c++;
	}
	if(max<=c)max=c;
	printf("%d",max);
}

/* Codeforces 774D - Lie or Truth
 * https://codeforces.com/problemset/problem/774/D
 * rating: 1500 | tags: *special, constructive algorithms, implementation, sortings
 * source: accepted submission #26152012 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int a[100005],b[100005];
int main()
{
	int i,l,r,n;
	scanf("%d%d%d",&n,&l,&r);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]!=a[i]&&(i<l||i>r))
		{
			printf("LIE\n");return 0;
		 } 
	}
	printf("TRUTH\n");return 0;
}

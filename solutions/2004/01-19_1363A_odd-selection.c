/* Codeforces 1363A - Odd Selection
 * https://codeforces.com/problemset/problem/1363/A
 * rating: 1200 | tags: brute force, implementation, math
 * source: accepted submission #82066411 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main()
{
	int i,j,k,n,t,z,x;
	scanf("%d",&t);
	for(int z1=0;z1<t;z1++)
	{
		scanf("%d%d",&n,&x);
		int a[n];
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]%2!=0)
			z++;
		}
		if(z==0)
		printf("No\n");
		else if(z==n&&x%2==0)
		printf("No\n");
		else if(x==n&&z%2==0)
		printf("No\n");
		else
		printf("Yes\n");
	}
}

/* Codeforces 593A - 2Char
 * https://codeforces.com/problemset/problem/593/A
 * rating: 1200 | tags: brute force, implementation
 * source: accepted submission #14065378 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main()
{
	int n,max=0,z,i,j,k;
	scanf("%d",&n);
	char a[n][1001],b,c;
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	for(b='a';b<='z';b++)
	{
		for(c=b;c<='z';c++)
		{
			z=0;
			for(i=0;i<n;i++)
			{
				k=0;
				for(j=0;j<strlen(a[i]);j++)
				{
					if(a[i][j]!=b && a[i][j]!=c)
					{
						k=1;
						break;
					}
				}
				if(k==0)
				{
					z=z+strlen(a[i]);
				}
			}
			if(z>max)
			{
				max=z;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}

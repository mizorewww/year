/* Codeforces 1256B - Minimize the Permutation
 * https://codeforces.com/problemset/problem/1256/B
 * rating: 1400 | tags: greedy
 * source: accepted submission #64254718 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int q,arr[1000],dup[1000];
	scanf("%d",&q);
	int i,j,n,ind[1000],a,p1,p2,min[1000],k;
	for(i=0;i<q;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[j]);
			ind[arr[j]]=j;
		}
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(k==j+1)
				{
					min[j]=arr[j+1];
				}
				else if(arr[k]<min[j])
				{
					min[j]=arr[k];
				}
			}
		}
		p1=0;
		while(p1!=n-1)
		{
			for(j=0;j<n;j++)
			{
				dup[j]=arr[j];
			}
			if(arr[p1]<min[p1])
			{
				p2=p1;
			}
			else
			{
				p2=ind[min[p1]];


			}
			if(p1==p2)
			{
				p1=p1+1;
			}
			else
			{
				int var,var2,var3;
				var3=arr[p1];
				var=arr[p2];
				for(j=p1;j<p2;j++)
				{
					arr[j+1]=dup[j];
				}
				arr[p1]=var;
				p1=p2;
			}
		}
	
	for(j=0;j<n;j++)
	{
		printf("%d ",arr[j]);
	}
	
	printf("\n");
	}
	return 0;
}

/* Codeforces 257A - Sockets
 * https://codeforces.com/problemset/problem/257/A
 * rating: 1100 | tags: greedy, implementation, sortings
 * source: accepted submission #2891735 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n,m,k,i,j,a[51];
	scanf("%d %d %d",&n,&m,&k);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;				
			}
		}
	}

	j=n-1;

	if(k>=m)
		printf("0\n");
	else
	{
		int req=m-(k-1);
		int flag=0;	

		while(req>1)
		{
			if(j<0)
			{
				printf("-1\n");
				flag=1;
				break;
			}
			
			req-=a[j]-1;
			j=j-1;
		}

		if(flag==0)
			printf("%d\n",n-1-j);

	}
}

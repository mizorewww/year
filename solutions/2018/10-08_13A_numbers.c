/* Codeforces 13A - Numbers
 * https://codeforces.com/problemset/problem/13/A
 * rating: 1000 | tags: implementation, math
 * source: accepted submission #20992939 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main ()
{int n,i,x,sum=0,sum1=0;
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{x=n;
		while (x!=0)
		{sum+=x%i;
			x/=i;
		}sum1+=sum;sum=0;}
	int k=n-2,r=0;
	int b=sum1,a=k;
	while(a!=0)
	{r=b%a;b=a;a=r;}
	printf("%d/%d",(sum1/b),(k/b));
	return 0;}

/* Codeforces 1056B - Divide Candies
 * https://codeforces.com/problemset/problem/1056/B
 * rating: 1600 | tags: math, number theory
 * source: accepted submission #46221721 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(void)
{
	int n;
	int m;
	scanf("%d",&n);
	long long int c=0;
	scanf("%d",&m);
	long long int ans[m];

	for(int i=0;i<m;i++)
	{
		ans[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		ans[(i*i)%m]++;
	}

	for(int i=0;i<m;i++)
	{
		ans[i]*=n/m;
	}

	for(int i=1;i<=n%m;i++)
	{
		ans[(i*i)%m]++;
	}
	c=ans[0]*ans[0];

	for(int i=1;i<m;i++)
	{
		c+=ans[i]*ans[m-i];
	}
	printf("%lld\n",c);


}

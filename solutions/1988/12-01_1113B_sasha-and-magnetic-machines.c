/* Codeforces 1113B - Sasha and Magnetic Machines
 * https://codeforces.com/problemset/problem/1113/B
 * rating: 1300 | tags: greedy, number theory
 * source: accepted submission #50009612 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
typedef long long int ll;
int main()
{
	ll n;
	scanf("%lld", &n);
	ll a[n], min=1e10, sum=0;

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &a[i]);
		if(a[i]<min)
			min=a[i];
		sum+=a[i];
	}
	ll mini=sum;
	for (int i = 0; i < n; ++i)
	{
		int temp=0, f=0;
		for(int j=2; j<a[i]; j++)
		{
			if(a[i]%j==0)
			{
				temp=sum-a[i]+a[i]/j-min+min*j;
				f=1;			
			}
			if(temp<mini&&f==1)
			mini=temp;
	
		}
		}
	printf("%lld\n", mini);

}

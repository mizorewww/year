/* Codeforces 1454D - Number into Sequence
 * https://codeforces.com/problemset/problem/1454/D
 * rating: 1300 | tags: constructive algorithms, math, number theory
 * source: accepted submission #99460844 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>
long long t;
long long n;
int main()
{
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld", &n);
		long long max=0, maxi;
		long long i;
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				long long cnt=0;
				long long tmp=n;
				while(tmp%i==0)
				{
					tmp/=i;
					cnt++;
				}
				//printf("%lld\n", cnt);
				if(max<cnt)
				{
					//printf("*%lld\n", cnt);
					max=cnt;
					maxi=i;
				}
			}
		}
		if(max==0)
		{
			printf("1\n%lld\n", n);
		}
		else
		{
			printf("%lld\n", max);
			for(long long i=1;i<max;i++)
			{
				printf("%lld ", maxi);
				n/=maxi;
			}
			printf("%lld\n", n);
			
		}
	}
}

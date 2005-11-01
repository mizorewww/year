/* Codeforces 1392C - Omkar and Waterslide
 * https://codeforces.com/problemset/problem/1392/C
 * rating: 1200 | tags: greedy, implementation
 * source: accepted submission #90131696 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int t, n, i;
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d", &n);
		int a[n+1];
		long long int s=0;
		
		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}
		for(i=n-1; i>0; i--)
		{
			if(a[i]<a[i-1])
			{
				s+=a[i-1]-a[i];
			}
		}
		printf("%lld\n", s);
	}
	return 0;
}

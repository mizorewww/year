/* Codeforces 1065A - Vasya and Chocolate
 * https://codeforces.com/problemset/problem/1065/A
 * rating: 800 | tags: implementation, math
 * source: accepted submission #44122334 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main()
{
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		printf("%lld\n",a/(b*d)*c+a/d);
	}
}

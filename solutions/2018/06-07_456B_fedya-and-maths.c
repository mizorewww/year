/* Codeforces 456B - Fedya and Maths
 * https://codeforces.com/problemset/problem/456/B
 * rating: 1200 | tags: math, number theory
 * source: accepted submission #7380679 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int main()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n%4 == 0) printf("4\n");
		else printf("0\n");
	}
	return 0;
}

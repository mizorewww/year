/* Codeforces 707C - Pythagorean Triples
 * https://codeforces.com/problemset/problem/707/C
 * rating: 1500 | tags: math, number theory
 * source: accepted submission #21208882 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()
{
	long long a,b,c;


	scanf("%lld",&a);
	if(a%2==1)
	{
		b=(a*a-1)/2;
		c=b+1;
	}
	else
	{
		b=(a/2)*(a/2)-1;
		c=b+2;
	}

	if(b+c>a)
	printf("%lld %lld",b,c);
	else
		printf("-1");
	

	return 0;
}

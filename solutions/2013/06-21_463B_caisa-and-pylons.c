/* Codeforces 463B - Caisa and Pylons
 * https://codeforces.com/problemset/problem/463/B
 * rating: 1100 | tags: brute force, implementation, math
 * source: accepted submission #7629428 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
int main()
{
	u n,i,r=0;
	for(scanf("%u",&n);n--;)
	{
		scanf("%u",&i);
		if(i>r)r=i;
	}
	printf("%u\n",r);
	return 0;
}

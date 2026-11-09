/* Codeforces 1475B - New Year's Number
 * https://codeforces.com/problemset/problem/1475/B
 * rating: 900 | tags: brute force, dp, math
 * source: accepted submission #105341489 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int qq,a,b;
	scanf("%d",&qq);
	while (qq--)
	{
		scanf("%d",&a);
		if (a/2020>=a%2020) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
 }

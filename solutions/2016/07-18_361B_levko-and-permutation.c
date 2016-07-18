/* Codeforces 361B - Levko and Permutation
 * https://codeforces.com/problemset/problem/361/B
 * rating: 1200 | tags: constructive algorithms, math, number theory
 * source: accepted submission #5049539 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main(void)
{
	int n, k, x, i;
	
	scanf("%d%d", &n,&k);
	if (n == k)
	{
		puts("-1");
		return 0;
	}
	x = n-k;
	for (i = 1; i < x; i++)
	{
		printf("%d ", i+1);
	}
	printf("1 ");
	for (i = x+1; i <= n; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}

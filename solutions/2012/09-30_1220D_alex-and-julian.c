/* Codeforces 1220D - Alex and Julian
 * https://codeforces.com/problemset/problem/1220/D
 * rating: 1900 | tags: bitmasks, math, number theory
 * source: accepted submission #60809706 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	long long int b[200005];
	for (i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	long long int k, mk, c, mc;
	mc = 1000000009;
	for (k = 1; k <= 1000000000000000018; k *= 2)
	{
		c = 0;
		for (i = 0; i < n; i++)
		{
			if (b[i] % k > 0)
				c++;
			else if (b[i] / k % 2 == 0)
				c++;
		}
		if (c < mc)
		{
			mc = c;
			mk = k;
		}
	}
	printf("%lld\n", mc);
	for (i = 0; i < n; i++)
	{
		if (b[i] % mk > 0)
		{
			printf("%lld", b[i]);
			mc--;
			if (mc > 0)
				printf(" ");
			else
				printf("\n");
		}
		else if (b[i] / mk % 2 == 0)
		{
			printf("%lld", b[i]);
			mc--;
			if (mc > 0)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}

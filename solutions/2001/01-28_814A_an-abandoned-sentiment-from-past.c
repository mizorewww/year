/* Codeforces 814A - An abandoned sentiment from past
 * https://codeforces.com/problemset/problem/814/A
 * rating: 900 | tags: constructive algorithms, greedy, implementation, sortings
 * source: accepted submission #27637430 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main()
{
	int n,k,i,t,b;
	int a[101];
	scanf("%d%d",&n,&k);
	if (k != 1)
	{
		printf("Yes\n");
		return 0;
	}
	for (i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		if (!a[i])
			t = i;
	}
	scanf("%d",&b);
	a[t] = b;
	for (i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}

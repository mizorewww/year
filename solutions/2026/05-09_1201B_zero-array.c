/* Codeforces 1201B - Zero Array
 * https://codeforces.com/problemset/problem/1201/B
 * rating: 1500 | tags: greedy, math
 * source: accepted submission #58273607 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	long long int a[100005];
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	long long int sum = 0, max = 0;
	for (i = 0; i < n; i++)
	{
		sum += a[i];
		if (max < a[i])
			max = a[i];
	}
	if (sum % 2 == 1)
		printf("NO\n");
	else if (sum < max * 2)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}

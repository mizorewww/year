/* Codeforces 1350B - Orac and Models
 * https://codeforces.com/problemset/problem/1350/B
 * rating: 1400 | tags: dp, math, number theory
 * source: accepted submission #79831137 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int n;
	int i, j;
	int s[100005];
	int ans[100005];
	for (; t > 0; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &s[i]);
		for (i = 0; i < n; i++)
			ans[i] = 1;
		for (i = 0; i < n; i++)
			for (j = 2; (i + 1) * j - 1 < n; j++)
				if (ans[(i + 1) * j - 1] < ans[i] + 1 && s[i] < s[(i + 1) * j - 1])
					ans[(i + 1) * j - 1] = ans[i] + 1;
		j = 0;
		for (i = 0; i < n; i++)
			if (ans[i] > j)
				j = ans[i];
		printf("%d\n", j);
	}
	return 0;
}

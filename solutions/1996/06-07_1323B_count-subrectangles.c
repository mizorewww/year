/* Codeforces 1323B - Count Subrectangles
 * https://codeforces.com/problemset/problem/1323/B
 * rating: 1500 | tags: binary search, greedy, implementation
 * source: accepted submission #72648259 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
long long CA[40002];
long long CB[40002];
int A[40002];
int B[40002];
int main()
{
	int i;
	long long t;
	int n, m, k;
	int c;
	long long R;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &B[i]);
	}
	for (i = 0; i <= 40000; i++)
	{
		CA[i] = 0;
	}
	c = 0;
	for (i = 0; i < n; i++)
	{
		if (A[i])
		{
			c++;
		}
		else
		{
			CA[c]++;
			c = 0;
		}
	}
	CA[c]++;
	for (i = 0; i <= 40000; i++)
	{
		CB[i] = 0;
	}
	c = 0;
	for (i = 0; i < m; i++)
	{
		if (B[i])
		{
			c++;
		}
		else
		{
			CB[c]++;
			c = 0;
		}
	}
	CB[c]++;
	R = 0;
	for (i = 40000; i > 0; i--)
	{
		CA[i - 1] += CA[i];
	}
	for (i = 40000; i > 0; i--)
	{
		CA[i - 1] += CA[i];
	}
	for (i = 40000; i > 0; i--)
	{
		CB[i - 1] += CB[i];
	}
	for (i = 40000; i > 0; i--)
	{
		CB[i - 1] += CB[i];
	}
	for (t = 1; t * t < k; t++)
	{
		if (k % t == 0)
		{
			if (k / t <= 40000)
			{
				R += CA[t] * CB[k / t];
				R += CA[k / t] * CB[t];
			}
		}
	}
	if (t * t == k)
	{
		R += CA[t] * CB[t];
	}
	printf("%I64d", R);
	return 0;
}

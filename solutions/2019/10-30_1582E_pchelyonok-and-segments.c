/* Codeforces 1582E - Pchelyonok and Segments
 * https://codeforces.com/problemset/problem/1582/E
 * rating: 2000 | tags: binary search, data structures, dp, greedy, math
 * source: accepted submission #132912904 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
long long A[100003];
long long S[100003];
long long M[502][100003];
int main()
{
	int i;
	int a;
	int t;
	int T;
	int n;
	long long temp;
	int R;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%I64d", &A[i]);
		}
		for (i = 1; i <= n; i++)
		{
			S[i] = A[i];
		}
		S[0] = 0;
		for (i = 1; i < n; i++)
		{
			S[i + 1] += S[i];
		}
		for (i = 1; i <= n; i++)
		{
			for (t = 0; t <= 500; t++)
			{
				M[t][i] = 0;
			}
		}
		M[0][n + 1] = 1000000001;
		for (i = 1; i <= 500; i++)
		{
			M[i][n + 1] = 0;
		}
		R = 0;
		for (t = n; t - R > 0; t--)
		{
			for (a = 0; a < R; a++)
			{
				temp = S[t] - S[t - a - 1];
				if (temp < M[a][t + 1])
				{
					if (temp > M[a + 1][t - a])
					{
						M[a + 1][t - a] = temp;
					}
				}
			}
			temp = S[t] - S[t - R - 1];
			if (temp < M[R][t + 1])
			{
				if (temp > M[R + 1][t - R])
				{
					M[R + 1][t - R] = temp;
				}
				R++;
			}
			for (a = 0; a <= R; a++)
			{
				if (M[a][t + 1] > M[a][t])
				{
					M[a][t] = M[a][t + 1];
				}
			}
		}
		printf("%d\n", R);
	}
	return 0;
}

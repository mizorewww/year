/* Codeforces 1095D - Circular Dance
 * https://codeforces.com/problemset/problem/1095/D
 * rating: 1600 | tags: implementation
 * source: accepted submission #47575918 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int n;
int arr[300000][2];
int out[300000];

int main()
{
	int n1, n2;
	int buf;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	if (n == 3)
	{
		for (int i = 1; i <= n; i++)
		{
			out[i] = i % n + 1;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			n1 = arr[i][0];
			n2 = arr[i][1];

			if (arr[n1][0] == n2 || arr[n1][1] == n2)
			{
				if (arr)
					out[i] = n1;
			}
			else
			{
				out[i] = n2;
			}
		}
	}

	buf = 1;

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", out[buf]);
		buf = out[buf];
	}

	return 0;
}

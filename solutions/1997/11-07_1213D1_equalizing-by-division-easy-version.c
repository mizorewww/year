/* Codeforces 1213D1 - Equalizing by Division (easy version)
 * https://codeforces.com/problemset/problem/1213/D1
 * rating: 1500 | tags: brute force, implementation
 * source: accepted submission #59754062 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
int asc(const void* a, const void* b)
{
	if (*(int*)a > * (int*)b)return 1;
	if (*(int*)a < *(int*)b)return -1;
	return 0;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int i, j;
	int a[200005];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), asc);
	int b[200005][20];
	for (i = 0; i < n; i++)
	{
		b[i][0] = a[i];
		for (j = 1; j < 20; j++)
			b[i][j] = b[i][j - 1] / 2;
	}
	int v[200005];
	for (i = 0; i < 200005; i++)
		v[i] = 0;
	int count;
	int ans = 2000000000;
	int x, y;
	int c;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (v[b[i][j]] == 0)
			{
				v[b[i][j]]++;
				count = 1;
				c = j;
				for (x = i + 1; x < n; x++)
				{
					for (y = 0; y < 20; y++)
					{
						if (b[x][y] < b[i][j])
							break;
						if (b[x][y] == b[i][j])
						{
							count++;
							c += y;
							break;
						}
					}
					if (count == k)
						break;
				}
				if (count == k)
					if (ans > c)
						ans = c;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

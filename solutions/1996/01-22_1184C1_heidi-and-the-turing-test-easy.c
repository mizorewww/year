/* Codeforces 1184C1 - Heidi and the Turing Test (Easy)
 * https://codeforces.com/problemset/problem/1184/C1
 * rating: 1600 | tags: implementation
 * source: accepted submission #56654051 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
int asc(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int x[50], y[50];
	for (i = 0; i < 4 * n + 1; i++)
		scanf("%d %d", &x[i], &y[i]);
	int xx[50], yy[50];
	for (i = 0; i < 4 * n + 1; i++)
		xx[i] = x[i];
	qsort(xx, 4 * n + 1, sizeof(int), asc);
	if (xx[0] != xx[1])
	{
		for (i = 0; i < 4 * n + 1; i++)
		{
			if (x[i] == xx[0])
			{
				printf("%d %d\n", x[i], y[i]);
				return 0;
			}
		}
	}
	if (xx[4 * n - 1] != xx[4 * n])
	{
		for (i = 0; i < 4 * n + 1; i++)
		{
			if (x[i] == xx[4 * n])
			{
				printf("%d %d\n", x[i], y[i]);
				return 0;
			}
		}
	}
	for (i = 0; i < 4 * n + 1; i++)
		yy[i] = y[i];
	qsort(yy, 4 * n + 1, sizeof(int), asc);
	if (yy[0] != yy[1])
	{
		for (i = 0; i < 4 * n + 1; i++)
		{
			if (y[i] == yy[0])
			{
				printf("%d %d\n", x[i], y[i]);
				return 0;
			}
		}
	}
	if (yy[4 * n - 1] != yy[4 * n])
	{
		for (i = 0; i < 4 * n + 1; i++)
		{
			if (y[i] == yy[4 * n])
			{
				printf("%d %d\n", x[i], y[i]);
				return 0;
			}
		}
	}
	int maxx, minx, maxy, miny;
	maxx = maxy = 0;
	minx = miny = 100;
	for (i = 0; i < 4 * n + 1; i++)
	{
		if (x[i] < minx)minx = x[i];
		if (x[i] > maxx)maxx = x[i];
		if (y[i] < miny)miny = y[i];
		if (y[i] > maxy)maxy = y[i];
	}
	for (i = 0; i < 4 * n + 1; i++)
	{
		if (x[i] != minx && x[i] != maxx && y[i] != miny && y[i] != maxy)
		{
			printf("%d %d\n", x[i], y[i]);
			return 0;
		}
	}
}

/* Codeforces 1208B - Uniqueness
 * https://codeforces.com/problemset/problem/1208/B
 * rating: 1500 | tags: binary search, brute force, implementation, two pointers
 * source: accepted submission #59468483 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
int asc(const void* a, const void* b)
{
	if (*(int*)a > * (int*)b)return 1;
	if (*(int*)a < *(int*)b)return -1;
	return 0;
}
int fmax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	int n;
	scanf("%d", &n);
	int i, j, k;
	int a[2003];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ans = 100005;
	int b[2003];
	int m = -1;
	for (i = n - 1; i >= 0; i--)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				m = i;
				break;
			}
		}
		if (m >= 0)
			break;
	}
	int max, min, mid;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
			b[j] = a[j];
		qsort(b, i, sizeof(int), asc);
		k = 0;
		for (j = 0; j < i - 1; j++)
			if (b[j] == b[j + 1])
				k++;
		if (k > 0)
			break;
		for (j = n - 1; j > fmax(i - 1, m); j--)
		{
			min = 0;
			max = i;
			while (max - min > 1)
			{
				mid = (max + min) / 2;
				if (b[mid] < a[j])
					min = mid;
				else
					max = mid;
			}
			if (b[min] < a[j])
				min++;
			if (b[min] == a[j])
				break;
		}
		if (ans > j - i + 1)
			ans = j - i + 1;
	}
	printf("%d\n", ans);
	return 0;
}

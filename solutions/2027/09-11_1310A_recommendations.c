/* Codeforces 1310A - Recommendations
 * https://codeforces.com/problemset/problem/1310/A
 * rating: 1700 | tags: data structures, greedy, sortings
 * source: accepted submission #71713635 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
long long int a[200005];
long long int t[200005];
int h[200005], l;
void swap_h(int x, int y)
{
	int f = h[x];
	h[x] = h[y];
	h[y] = f;
	return;
}
int comp_h(int x, int y,int q)
{
	if (q == 0)
	{
		if (a[h[x]] > a[h[y]])return 1;
		return -1;
	}
	else
	{
		if (t[h[x]] < t[h[y]])return 1;
		return -1;
	}
}
void f1(int n, int q)
{
	h[l] = n;
	int now = l;
	l++;
	while (now > 0)
	{
		if (comp_h((now - 1) / 2, now, q) > 0)
			swap_h((now - 1) / 2, now);
		now = (now - 1) / 2;
	}
	return;
}
int f2(int q)
{
	l--;
	swap_h(0, l);
	int now = 0;
	for (;;)
	{
		if (2 * now + 2 < l)
		{
			if (comp_h(2 * now + 1, 2 * now + 2, q) > 0)
			{
				if (comp_h(now, 2 * now + 2, q) > 0)
					swap_h(now, 2 * now + 2);
				now = 2 * now + 2;
			}
			else
			{
				if (comp_h(now, 2 * now + 1, q) > 0)
					swap_h(now, 2 * now + 1);
				now = 2 * now + 1;
			}
		}
		else if (2 * now + 1 < l)
		{
			if (comp_h(now, 2 * now + 1, q) > 0)
				swap_h(now, 2 * now + 1);
			now = 2 * now + 1;
		}
		else
			break;
	}
	return h[l];
}
int main()
{
	int n;
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%lld", &t[i]);
	l = 0;
	for (i = 0; i < n; i++)
		f1(i, 0);
	int c[200005];
	for (i = 0; i < n; i++)
		c[i] = f2(0);
	long long int ans = 0;
	l = 0;
	long long int na = 0;
	int r = 0;
	for (i = 0; i < n; i++)
	{
		if (l == 0)
		{
			na = a[c[r]];
			f1(c[r], 1);
			r++;
		}
		if (r < n)
		{
			while (a[c[r]] == na)
			{
				f1(c[r], 1);
				r++;
				if (r == n)
					break;
			}
		}
		j = f2(1);
		ans += t[j] * (na - a[j]);
		na++;
	}
	printf("%lld\n", ans);
	return 0;
}

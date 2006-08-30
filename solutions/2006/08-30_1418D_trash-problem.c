/* Codeforces 1418D - Trash Problem
 * https://codeforces.com/problemset/problem/1418/D
 * rating: 2100 | tags: data structures, implementation
 * source: accepted submission #92834752 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int h[200005], l;
int comp_h(int a, int b)
{
	if (h[a] > h[b])
		return 1;
	else
		return -1;
}
void swap_h(int a, int b)
{
	int f = h[a];
	h[a] = h[b];
	h[b] = f;
	return;
}
void push(int ne)
{
	h[l] = ne;
	int p = l;
	l++;
	for (; p > 0; p = (p - 1) / 2)
		if (comp_h((p - 1) / 2, p) > 0)
			swap_h((p - 1) / 2, p);
	return;
}
int pop()
{
	l--;
	swap_h(0, l);
	int p = 0;
	for (;;)
	{
		if (2 * p + 2 < l)
		{
			if (comp_h(2 * p + 1, 2 * p + 2) > 0)
			{
				if (comp_h(p, 2 * p + 2) > 0)
					swap_h(p, 2 * p + 2);
				p = 2 * p + 2;
			}
			else
			{
				if (comp_h(p, 2 * p + 1) > 0)
					swap_h(p, 2 * p + 1);
				p = 2 * p + 1;
			}
		}
		else if (2 * p + 1 < l)
		{
			if (comp_h(p, 2 * p + 1) > 0)
				swap_h(p, 2 * p + 1);
			p = 2 * p + 1;
		}
		else
			break;
	}
	return h[l];
}
int seg1[800005], seg2[800005], seg3[800005], ss;
void set1(int x, int v)
{
	x += ss - 1;
	seg1[x] = v;
	while (x > 0)
	{
		x = (x - 1) / 2;
		if (seg1[2 * x + 1] > seg1[2 * x + 2])
			seg1[x] = seg1[2 * x + 1];
		else
			seg1[x] = seg1[2 * x + 2];
	}
	return;
}
int get1(int l, int r)
{
	int res = -1;
	l += ss - 1;
	r += ss - 1;
	while (l < r)
	{
		if (l % 2 == 0 && res < seg1[l])
			res = seg1[l];
		l /= 2;
		if (r % 2 > 0 && res < seg1[r])
			res = seg1[r];
		r = r / 2 - 1;
	}
	if (l == r && res < seg1[l])
		res = seg1[l];
	return res;
}
void set2(int x, int v)
{
	x += ss - 1;
	seg2[x] = v;
	while (x > 0)
	{
		x = (x - 1) / 2;
		if (seg2[2 * x + 1] < seg2[2 * x + 2])
			seg2[x] = seg2[2 * x + 1];
		else
			seg2[x] = seg2[2 * x + 2];
	}
	return;
}
int get2(int l, int r)
{
	int res = ss;
	l += ss - 1;
	r += ss - 1;
	while (l < r)
	{
		if (l % 2 == 0 && res > seg2[l])
			res = seg2[l];
		l /= 2;
		if (r % 2 > 0 && res > seg2[r])
			res = seg2[r];
		r = r / 2 - 1;
	}
	if (l == r && res > seg2[l])
		res = seg2[l];
	return res;
}
void set3(int x, int v)
{
	x += ss - 1;
	seg3[x] = v;
	while (x > 0)
	{
		x = (x - 1) / 2;
		if (seg3[2 * x + 1] > seg3[2 * x + 2])
			seg3[x] = seg3[2 * x + 1];
		else
			seg3[x] = seg3[2 * x + 2];
	}
	return;
}
int get3(int l, int r)
{
	int res = -1;
	l += ss - 1;
	r += ss - 1;
	while (l < r)
	{
		if (l % 2 == 0 && res < seg3[l])
			res = seg3[l];
		l /= 2;
		if (r % 2 > 0 && res < seg3[r])
			res = seg3[r];
		r = r / 2 - 1;
	}
	if (l == r && res < seg3[l])
		res = seg3[l];
	return res;
}
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	int i, j, k;
	int p[100005];
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);
	int t[100005], x[100005];
	for (i = 0; i < q; i++)
		scanf("%d %d", &t[i], &x[i]);
	l = 0;
	for (i = 0; i < n; i++)
		push(p[i]);
	for (i = 0; i < q; i++)
		push(x[i]);
	int d[200005], m = 0;
	d[m] = pop();
	m++;
	while (l > 0)
	{
		d[m] = pop();
		if (d[m] > d[m - 1])
			m++;
	}
	int min, mid, max;
	int pp[100005], xx[100005];
	for (i = 0; i < n; i++)
	{
		min = -1;
		max = m;
		while (max - min > 1)
		{
			mid = (max + min) / 2;
			if (d[mid] < p[i])
				min = mid;
			else
				max = mid;
		}
		pp[i] = max;
	}
	for (i = 0; i < q; i++)
	{
		min = -1;
		max = m;
		while (max - min > 1)
		{
			mid = (max + min) / 2;
			if (d[mid] < x[i])
				min = mid;
			else
				max = mid;
		}
		xx[i] = max;
	}
	ss = 1;
	while (ss < m)
		ss *= 2;
	for (i = 0; i < 2 * ss - 1; i++)
		seg1[i] = -1;
	for (i = 0; i < 2 * ss - 1; i++)
		seg2[i] = ss;
	for (i = 0; i < 2 * ss - 1; i++)
		seg3[i] = 0;
	for (i = 0; i < n; i++)
	{
		set1(pp[i], pp[i]);
		set2(pp[i], pp[i]);
		j = get1(0, pp[i] - 1);
		if (j >= 0)
			set3(j, p[i] - d[j]);
		j = get2(pp[i] + 1, m);
		if (j < m)
			set3(pp[i], d[j] - p[i]);
	}
	printf("%d\n", d[get1(0, m)] - d[get2(0, m)] - get3(0, m));
	int cnt = n;
	for (i = 0; i < q; i++)
	{
		if (t[i] == 0)
		{
			cnt--;
			set1(xx[i], -1);
			set2(xx[i], ss);
			set3(xx[i], 0);
			j = get1(0, xx[i] - 1);
			if (j >= 0)
			{
				k = get2(j + 1, m);
				if (k < m)
					set3(j, d[k] - d[j]);
				else
					set3(j, 0);
			}
			if (cnt == 0)
				printf("0\n");
			else
				printf("%d\n", d[get1(0, m)] - d[get2(0, m)] - get3(0, m));
		}
		else
		{
			cnt++;
			set1(xx[i], xx[i]);
			set2(xx[i], xx[i]);
			j = get1(0, xx[i] - 1);
			if (j >= 0)
				set3(j, x[i] - d[j]);
			j = get2(xx[i] + 1, m);
			if (j < m)
				set3(xx[i], d[j] - x[i]);
			printf("%d\n", d[get1(0, m)] - d[get2(0, m)] - get3(0, m));
		}
	}
	return 0;
}

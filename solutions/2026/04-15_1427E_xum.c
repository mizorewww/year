/* Codeforces 1427E - Xum
 * https://codeforces.com/problemset/problem/1427/E
 * rating: 2500 | tags: bitmasks, constructive algorithms, math, matrices, number theory
 * source: accepted submission #95144267 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
long long int f(long long int n)
{
	long long int res = 1;
	while ((res & n) == 0)
		res *= 2;
	return res;
}
int main()
{
	long long int x;
	scanf("%lld", &x);
	long long int p = 1;
	long long int cnt = 0, ans[100005][3], i;
	if ((x & 2) > 0)
	{
		ans[cnt][0] = x;
		ans[cnt][1] = 0;
		ans[cnt][2] = x;
		cnt++;
		x *= 2;
		ans[cnt][0] = x / 2;
		ans[cnt][1] = 1;
		ans[cnt][2] = x;
		cnt++;
		x = (x ^ (x / 2));
	}
	while (p <= x)
		p *= 2;
	p *= 2;
	long long int r = x, a = x;
	while (f(r - 1) < p)
	{
		while (f(r - 1) != f(a))
		{
			ans[cnt][0] = a;
			ans[cnt][1] = 0;
			ans[cnt][2] = a;
			cnt++;
			a *= 2;
		}
		ans[cnt][0] = r;
		ans[cnt][1] = 1;
		ans[cnt][2] = a;
		cnt++;
		r ^= a;
	}
	ans[cnt][0] = r;
	ans[cnt][1] = 1;
	ans[cnt][2] = x;
	cnt++;
	ans[cnt][0] = r;
	ans[cnt][1] = 0;
	ans[cnt][2] = x;
	cnt++;
	ans[cnt][0] = r + x;
	ans[cnt][1] = 1;
	ans[cnt][2] = r;
	cnt++;
	ans[cnt][0] = ((r + x) ^ r);
	ans[cnt][1] = 1;
	ans[cnt][2] = x;
	cnt++;
	long long int q = ((r + x) ^ r ^ x);
	while (r > 1)
	{
		if ((q & r) > 0)
		{
			ans[cnt][0] = r;
			ans[cnt][1] = 1;
			ans[cnt][2] = q;
			r ^= q;
			cnt++;
		}
		ans[cnt][0] = q;
		ans[cnt][1] = 0;
		ans[cnt][2] = q;
		cnt++;
		q *= 2;
	}
	printf("%lld\n", cnt);
	for (i = 0; i < cnt; i++)
	{
		printf("%lld ", ans[i][0]);
		if (ans[i][1] == 0)
			printf("+ ");
		else
			printf("^ ");
		printf("%lld\n", ans[i][2]);
	}
	return 0;
}

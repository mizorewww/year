/* Codeforces 1349A - Orac and LCM
 * https://codeforces.com/problemset/problem/1349/A
 * rating: 1600 | tags: data structures, math, number theory
 * source: accepted submission #79848076 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
long long int prime(long long int n)
{
	if (n < 2)
		return 0;
	long long int i;
	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return i;
	return n;
}
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	long long int a[100005];
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	long long int ans = 1;
	long long int p, q = a[0] * a[1];
	long long int c, m1, m2;
	while (q > 1)
	{
		p = prime(q);
		m1 = m2 = -1;
		for (i = 0; i < n; i++)
		{
			c = 0;
			while (a[i] % p == 0)
			{
				c++;
				a[i] /= p;
			}
			if (m1 < 0 || c < m1)
			{
				m2 = m1;
				m1 = c;
			}
			else if (m2 < 0 || c < m2)
				m2 = c;
		}
		for (m1 = 0; m1 < m2; m1++)
			ans *= p;
		q = a[0] * a[1];
	}
	printf("%lld\n", ans);
	return 0;
}

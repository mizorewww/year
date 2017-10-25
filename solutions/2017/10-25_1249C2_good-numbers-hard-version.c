/* Codeforces 1249C2 - Good Numbers (hard version)
 * https://codeforces.com/problemset/problem/1249/C2
 * rating: 1500 | tags: binary search, greedy, math, meet-in-the-middle
 * source: accepted submission #63166246 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
long long BP(long long a, long long b)
{
	long long r = 1;
	while (b)
	{
		if (b & 1)
		{
			r *= a;
		}
		a *= a;
		b >>= 1;
	}
	return r;
}
int main()
{
	int Q;
	long long n;
	long long t;
	long long tS;
	long long temp;
	long long R;
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%I64d", &n);
		tS = 0;
		for (t = 37; t >= 0; t--)
		{
			temp = BP(3, t);
			if (temp < n)
			{
				n -= temp;
				tS ^= BP(2, t);
			}
		}
		tS += 1;
		R = 0;
		for (t = 0; t <= 38; t++)
		{
			if (tS & 1)
			{
				R += BP(3, t);
			}
			tS >>= 1;
		}
		printf("%I64d\n", R);
	}
	return 0;
}

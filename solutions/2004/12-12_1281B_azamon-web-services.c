/* Codeforces 1281B - Azamon Web Services
 * https://codeforces.com/problemset/problem/1281/B
 * rating: 1600 | tags: greedy
 * source: accepted submission #66906829 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int fmin(int a, int b)
{
	if (a < b)return a;
	else return b;
}
int main()
{
	int t;
	scanf("%d", &t);
	int i, j, k;
	char s[5003], c[5003];
	int n, m;
	int min, last;
	for (j = 0; j < t; j++)
	{
		scanf("%s%s", s, c);
		n = strlen(s);
		m = strlen(c);
		for (i = 0; i < n; i++)
		{
			min = i;
			for (k = i; k < n; k++)
				if (s[k] < s[min])
					min = k;
			if (s[i] > s[min])
			{
				for (k = n - 1; k > i; k--)
				{
					if (s[k] == s[min])
					{
						last = k;
						break;
					}
				}
				s[i] ^= s[last];
				s[last] ^= s[i];
				s[i] ^= s[last];
				break;
			}
		}
		k = 0;
		for (i = 0; i < fmin(m, n); i++)
		{
			if (s[i] < c[i])
			{
				k = 1;
				break;
			}
			if (s[i] > c[i])
			{
				k = -1;
				break;
			}
		}
		if (k == 0)
		{
			if (n < m)
				k = 1;
			else
				k = -1;
		}
		if (k > 0)
			printf("%s\n", s);
		else
			printf("---\n");
	}
	return 0;
}

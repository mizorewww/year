/* Codeforces 1381B - Unmerge
 * https://codeforces.com/problemset/problem/1381/B
 * rating: 1800 | tags: dp
 * source: accepted submission #87552547 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int tn;
int n, m;
int a[4040];
int p[4040];
int c[4040];
int main(void)
{
	scanf("%d", &tn);
	c[0] = 1;
	while (tn--)
	{
		scanf("%d", &n);
		m = 2 * n;
		for (int i = 0; i < 2 * n; i++)
		{
			scanf("%d", a + i);
			p[i + 1] = 0;
			c[i + 1] = 0;
		}
		for (int i = 2 * n - 1; i >= 0; i--)
		{
			int pos = i;
			while (a[pos] != m)
			{
				p[a[pos]] = 1;
				pos--;
			}
			p[a[pos]] = 1;
			int d = i - pos + 1;
			for (int j = n; j >= d; j--)if (c[j - d])c[j] = 1;
			while (m >= 0 && p[m])m--;
			i = pos;
		}
		printf("%s\n", c[n] ? "YES" : "NO");
	}
}

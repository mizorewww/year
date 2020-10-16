/* Codeforces 721B - Passwords
 * https://codeforces.com/problemset/problem/721/B
 * rating: 1100 | tags: implementation, math, sortings, strings
 * source: accepted submission #21022839 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

int main()
{
	int n, m, i, x, y;
	int cnt[200];
	char s[200];

	memset(cnt, 0, sizeof(cnt));
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", s);
		cnt[strlen(s)]++;
	}
	scanf("%s", s);
	x = 0;
	y = cnt[strlen(s)];
	for (i = strlen(s) - 1; i > 0; i--)
		x += cnt[i];
	printf("%d %d\n", x + 1 + x / m * 5, x + y + (x + y - 1) / m * 5);
	return 0;
}

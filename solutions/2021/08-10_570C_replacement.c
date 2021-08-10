/* Codeforces 570C - Replacement
 * https://codeforces.com/problemset/problem/570/C
 * rating: 1600 | tags: constructive algorithms, data structures, implementation
 * source: accepted submission #12503693 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

char s[333333];

int main() {
	int i, x, n, m, ans = 0;
	char c;

	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	s[0] = s[n+1] = 'a';

	for (i = 1; i <= n; i++)
		if (s[i-1] == '.' && s[i] == '.')
			ans++;

	while (m--) {
		scanf("%d%*c%c", &x, &c);
		if (c == '.' && s[x] != '.') {
			if (s[x-1] == '.')
				ans++;
			if (s[x+1] == '.')
				ans++;
		}
		else if (c != '.' && s[x] == '.') {
			if (s[x-1] == '.')
				ans--;
			if (s[x+1] == '.')
				ans--;
		}
		s[x] = c;
		printf("%d\n", ans);
	}

	return 0;
}

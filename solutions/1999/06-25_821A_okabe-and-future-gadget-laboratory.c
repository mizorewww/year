/* Codeforces 821A - Okabe and Future Gadget Laboratory
 * https://codeforces.com/problemset/problem/821/A
 * rating: 800 | tags: implementation
 * source: accepted submission #28027698 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int a[50][50];

int main() {
	int x, y, s, t, n, ok = 1;

	scanf("%d", &n);
	for (x = 0; x < n; x++)
		for (y = 0; y < n; y++)
			scanf("%d", &a[x][y]);

	for (x = 0; x < n; x++)
		for (y = 0; y < n; y++)
			if (a[x][y] != 1) {
				int flag = 0;
				for (s = 0; s < n; s++)
					for (t = 0; t < n; t++)
						if (a[x][s] + a[t][y] == a[x][y])
							flag = 1;
				if (!flag)
					ok = 0;
			}

	if (ok)
		puts("Yes");
	else
		puts("No");

	return 0;
}

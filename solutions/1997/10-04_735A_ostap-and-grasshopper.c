/* Codeforces 735A - Ostap and Grasshopper
 * https://codeforces.com/problemset/problem/735/A
 * rating: 800 | tags: implementation, strings
 * source: accepted submission #22551852 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

char a[101];

int main() {

	unsigned char n, k;
	scanf("%hhu %hhu\n", &n, &k);
	scanf("%s", a);

	unsigned char i;
	for (i = 0; i < n; i++) {
		if (a[i] == 'T' || a[i] == 'G')
			break;
	}

	for (i += k; i < n; i += k) {
		switch (a[i]) {
		case '#':
			printf("NO");
			return 0;
			break;
		case 'G':
		case 'T':
			printf("YES");
			return 0;
			break;
		}
	}

	printf("NO");
	return 0;
}

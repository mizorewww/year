/* Codeforces 1133A - Middle of the Contest
 * https://codeforces.com/problemset/problem/1133/A
 * rating: 1000 | tags: implementation
 * source: accepted submission #50941850 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main() {
	int h1, h2, m1, m2;
	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);
	int m = ((h1 + h2) * 60 + m1 + m2) / 2;
	printf("%02d:%02d\n", m / 60, m % 60);
	return 0;
}

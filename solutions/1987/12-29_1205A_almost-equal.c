/* Codeforces 1205A - Almost Equal
 * https://codeforces.com/problemset/problem/1205/A
 * rating: 1200 | tags: constructive algorithms, greedy, math
 * source: accepted submission #59021023 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main() {
	int n, i;
	scanf("%d", &n);
	if(n & 1) {
		printf("YES\n");
		for(i = 0; i < n; i++)
			printf(i ? " %d" : "%d", 2*i + 1 + !!(i&1));
		for(i = 0; i < n; i++)
			printf(" %d", 2*i + 1 + !(i&1));
	} else
		printf("NO");
	return 0;
}

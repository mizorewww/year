/* Codeforces 412B - Network Configuration
 * https://codeforces.com/problemset/problem/412/B
 * rating: 900 | tags: greedy, sortings
 * source: accepted submission #6407388 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
int f(const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}
int main(void) {
	int i,n,k;
	scanf("%d%d", &n, &k);
	int a[n];
	for(i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), f);
	printf("%d", a[n-k]);
	return 0;
}

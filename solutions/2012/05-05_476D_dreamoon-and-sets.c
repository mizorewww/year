/* Codeforces 476D - Dreamoon and Sets
 * https://codeforces.com/problemset/problem/476/D
 * rating: 1900 | tags: constructive algorithms, greedy, math
 * source: accepted submission #8201486 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main(void)
{
	int n, k, i, cnt;
	
	scanf("%d%d", &n, &k);
	printf("%d\n", k*(6*(n-1)+5));
	cnt = 1;
	for (i=0; i<n; ++i) {
		if (cnt%3 == 0)
			++cnt;
		printf("%d %d %d %d\n", k*2*cnt, k*(6*i+1), k*(6*i+3), k*(6*i+5));
		++cnt;
	}
	
	return 0;
}

/* Codeforces 1415A - Prison Break
 * https://codeforces.com/problemset/problem/1415/A
 * rating: 800 | tags: brute force, math
 * source: accepted submission #99844869 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main(){
	int t, n, m, r, c; scanf("%d", &t);
	for (int _ = 0; _ < t; _++){
		scanf("%d %d %d %d", &n, &m, &r, &c);
		if (r - 1 < n - r ){ r = n - r; }else{ r--; }
		if (c - 1 < m - c ){ c = m - c; }else{ c--; }
		printf("%d\n", r + c);
	}
	return 0;
}

/* Codeforces 140A - New Year Table
 * https://codeforces.com/problemset/problem/140/A
 * rating: 1700 | tags: geometry, math
 * source: accepted submission #999141 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>

int main() {
	int n,R,r;
	double a;
	scanf("%d %d %d",&n,&R,&r);
	if (r>R) puts("NO");
	else if (r+r>R) {
		if (n==1) puts("YES"); else puts("NO");
	} else {
		a=asin((double)r/(R-r));
		if (acos(-1)-a*n>-1e-12) puts("YES"); else puts("NO");
	}
	return 0;
}

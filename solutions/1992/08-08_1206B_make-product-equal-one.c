/* Codeforces 1206B - Make Product Equal One
 * https://codeforces.com/problemset/problem/1206/B
 * rating: 900 | tags: dp, implementation
 * source: accepted submission #59026552 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main() {
	int n, si = 1, z = 0;
	long long o = 0;
	scanf("%d", &n);
	while(n--) {
		long long a;
		scanf("%lld", &a);
		if(!a) {
			z++;
			continue;
		}
		o += (a>0?a:-a) - 1;
		if(a < 0)
			si *= -1;
	}
	printf("%lld", o + (z ? z : 2*(si == -1)));
	return 0;
}

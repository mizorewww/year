/* Codeforces 226A - Flying Saucer Segments
 * https://codeforces.com/problemset/problem/226/A
 * rating: 1400 | tags: math
 * source: accepted submission #2242234 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main()
{
	int n, m, res, t;
	scanf("%d%d", &n, &m);
	for ( res = 1, t = 3; n; n >>= 1 )
	{
		if ( n & 1 )
			res = res * (long long) t % m;
		t = t * (long long) t % m;
	}
	if ( --res < 0 )
		res += m;
	printf("%d\n", res);
	return 0;
}

/* Codeforces 1181A - Chunga-Changa
 * https://codeforces.com/problemset/problem/1181/A
 * rating: 1000 | tags: greedy, math
 * source: accepted submission #55625665 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>
typedef long long ll;
#define MIN(a,b) ((a>b)?(b):(a))
int main()
{
	ll x, y, z;
	scanf("%I64d%I64d%I64d", &x, &y, &z);

	printf("%I64d %I64d", (x + y) / z, (x%z + y%z < z)?0:MIN(z-x%z,z-y%z));

	return 0;
}

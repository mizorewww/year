/* Codeforces 519B - A and B and Compilation Errors
 * https://codeforces.com/problemset/problem/519/B
 * rating: 1100 | tags: data structures, implementation, sortings
 * source: accepted submission #19882999 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main()

{

	int n,i,t,a = 0,b = 0, c = 0;

	scanf("%d",&n);

	for(i = 0; i < n; i++)

		scanf("%d",&t),a^=t;

	for(i = 0; i < n - 1; i++)

		scanf("%d",&t),b^=t;

	for(i = 0; i < n - 2; i++)

		scanf("%d",&t),c^=t;

	printf("%d\n%d",a^b,b^c);

}

/* Codeforces 1421A - XORwice
 * https://codeforces.com/problemset/problem/1421/A
 * rating: 800 | tags: bitmasks, greedy, math
 * source: accepted submission #95888026 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main()
{
    int x,a,b,c;
    scanf("%d",&x);
    while(x--)
    {
    	scanf("%d %d",&a,&b);
		c=a^b;
		printf("%d\n",c);
	}
	return 0;
}

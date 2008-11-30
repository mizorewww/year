/* Codeforces 1223A - CME
 * https://codeforces.com/problemset/problem/1223/A
 * rating: 800 | tags: math
 * source: accepted submission #61992813 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main(void)
{
	int q,a;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&a);
		if(a==2) printf("2\n");
		else printf("%d\n",a%2);
	}
	return 0;
}

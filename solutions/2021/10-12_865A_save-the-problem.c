/* Codeforces 865A - Save the problem!
 * https://codeforces.com/problemset/problem/865/A
 * rating: 1400 | tags: constructive algorithms
 * source: accepted submission #30876642 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	if (a==1)
	{
		printf("1 2\n1 5\n");
		return 0;
	}
	printf("%d 2\n", 5*(a-1));
	printf("1 5\n");
	return 0;
}

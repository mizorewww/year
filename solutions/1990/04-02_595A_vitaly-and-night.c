/* Codeforces 595A - Vitaly and Night
 * https://codeforces.com/problemset/problem/595/A
 * rating: 800 | tags: constructive algorithms, implementation
 * source: accepted submission #14146756 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int i,n,m,x,y,sum=0;
	scanf("%i%i",&n,&m);
	for (i=0;i<m*n;i++)
	{
		scanf("%i%i",&x,&y);
		if (x || y)
			sum++; 
	}
	printf("%i",sum);
	return 0;
}

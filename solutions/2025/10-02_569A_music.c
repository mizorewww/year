/* Codeforces 569A - Music
 * https://codeforces.com/problemset/problem/569/A
 * rating: 1500 | tags: implementation, math
 * source: accepted submission #12445263 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main(void) {
	int t,s,q,a=1;
	scanf("%d%d%d",&t,&s,&q);
	while(s+s*(q-1)<t)
	{
		a++;
		s=s+s*(q-1);
	}
	printf("%d",a);
	return 0;
}

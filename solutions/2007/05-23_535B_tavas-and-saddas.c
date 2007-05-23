/* Codeforces 535B - Tavas and SaDDas
 * https://codeforces.com/problemset/problem/535/B
 * rating: 1100 | tags: bitmasks, brute force, combinatorics, implementation
 * source: accepted submission #10708258 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main ()
{
	int s=0,n,r,t;
	scanf("%d",&n);
	t=n;
	while(t)t/=10,r++;
	s+=(1<<r)-1;
	t=n;
	r=0;
	while(t)
	{
	if (t%10==7)
		s+=1<<r;
	r++;
	t/=10;
	}
	printf("%d",s);
return  0;
}

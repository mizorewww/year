/* Codeforces 626A - Robot Sequence
 * https://codeforces.com/problemset/problem/626/A
 * rating: 1000 | tags: brute force, implementation
 * source: accepted submission #15991714 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u M[444][444];
int main()
{
	u t,x=222,y=222,r=0;char c;
	for(scanf("%u",&t);t--;r+=M[x+=(c=='R')-(c=='L')][y+=(c=='U')-(c=='D')])
	for(++M[x][y];(c=getchar())<'A';);
	printf("%u\n",r);
	return 0;
}

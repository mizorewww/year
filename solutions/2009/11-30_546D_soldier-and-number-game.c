/* Codeforces 546D - Soldier and Number Game
 * https://codeforces.com/problemset/problem/546/D
 * rating: 1700 | tags: constructive algorithms, dp, math, number theory
 * source: accepted submission #11216803 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#define lim 5555555
typedef unsigned u;
u N[lim];
int main()
{
	u i,j,t;
	for(i=1;++i<lim;N[i]+=N[i-1])if(!N[i])
	{
		for(t=1;t<=lim/i;)
		for(++N[j=(t*=i)];(j+=t)<lim;++N[j]);
	}
	for(scanf("%u",&t);t--;)
	{
		scanf("%u%u",&i,&j);
		printf("%u\n",N[i]-N[j]);
	}
	return 0;
}

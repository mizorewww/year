/* Codeforces 757A - Gotta Catch Em' All!
 * https://codeforces.com/problemset/problem/757/A
 * rating: 1000 | tags: implementation
 * source: accepted submission #23741915 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u F[128];
int main()
{
	char c;u r=-1;
	while((c=getchar())>' ')++F[(u)c];
	if(r>(F['B']/=1))r=F['B'];
	if(r>(F['u']/=2))r=F['u'];
	if(r>(F['l']/=1))r=F['l'];
	if(r>(F['b']/=1))r=F['b'];
	if(r>(F['a']/=2))r=F['a'];
	if(r>(F['s']/=1))r=F['s'];
	if(r>(F['r']/=1))r=F['r'];
	printf("%u\n",r);
	return 0;
}

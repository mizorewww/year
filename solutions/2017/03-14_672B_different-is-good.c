/* Codeforces 672B - Different is Good
 * https://codeforces.com/problemset/problem/672/B
 * rating: 1000 | tags: constructive algorithms, implementation, strings
 * source: accepted submission #17848835 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u C[33];
int main()
{
	u n,i,j;char c;
	scanf("%u",&n);
	if(n>26){printf("-1\n");return 0;}
	for(i=-1;++i<n;++C[c-'a'])while((c=getchar())<'a');
	for(i=-1,j=0;++i<33;)if(C[i])++j;
	printf("%u\n",n-j);
	return 0;
}

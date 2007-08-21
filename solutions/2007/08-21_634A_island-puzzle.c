/* Codeforces 634A - Island Puzzle
 * https://codeforces.com/problemset/problem/634/A
 * rating: 1300 | tags: constructive algorithms, implementation
 * source: accepted submission #16409560 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u A[444444];
int main()
{
	u n,i=-1,j;
	for(scanf("%u",&n);++i<n;scanf("%u",A+i));
	for(i=-1;++i<n;)A[i+n]=A[i];
	for(j=0;!j;scanf("%u",&j))--n;
	for(i=-1;A[++i]!=j;);
	while(n--)
	{
		scanf("%u",&j);
		if(!j)continue;
		while(!A[++i]);
		if(A[i]!=j){printf("NO\n");return 0;}
	}
	printf("YES\n");
	return 0;
}

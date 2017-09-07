/* Codeforces 1092A - Uniform String
 * https://codeforces.com/problemset/problem/1092/A
 * rating: 800 | tags: implementation
 * source: accepted submission #47197282 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int n,t;
int i,j,k;
int main()
{
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&k);
		for(j=0;j<n;j++)printf("%c",97+j%k);
		printf("\n");
	}
}

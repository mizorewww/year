/* Codeforces 285A - Slightly Decreasing Permutations
 * https://codeforces.com/problemset/problem/285/A
 * rating: 1100 | tags: greedy, implementation
 * source: accepted submission #3368322 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int n,k,i,j;
scanf("%d%d",&n,&k);
for(i=1;i<=n-k-1;i++)
printf("%d ",i);
for(j=n;j>=i;j--)
printf("%d ",j);
return 0;
}

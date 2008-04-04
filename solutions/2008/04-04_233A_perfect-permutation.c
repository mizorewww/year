/* Codeforces 233A - Perfect Permutation
 * https://codeforces.com/problemset/problem/233/A
 * rating: 800 | tags: implementation, math
 * source: accepted submission #2341995 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()
{
int i,n;
scanf("%d",&n);
if(n%2==1)
printf("-1");
else
{
for(i=1;i<=n/2;i++)
printf("%d %d ",2*i,2*i-1);
}
return 0;
}

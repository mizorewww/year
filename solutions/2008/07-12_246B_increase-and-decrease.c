/* Codeforces 246B - Increase and Decrease
 * https://codeforces.com/problemset/problem/246/B
 * rating: 1300 | tags: greedy, math
 * source: accepted submission #2619869 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()
{
int i,j,n,a[100000],sum=0;
scanf("%d",&n);
for(i=0;i<n;i++)
 scanf("%d",&a[i]);
for(i=0;i<n;i++)
 sum+=a[i];
if(sum%n==0)
 printf("%d\n",n);
else
 printf("%d\n",n-1);
return 0;
}

/* Codeforces 270B - Multithreading
 * https://codeforces.com/problemset/problem/270/B
 * rating: 1400 | tags: data structures, greedy, implementation
 * source: accepted submission #3052636 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int n,i,a[100001],j;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=n-1,j=1;i>0;i--,j++)
if(a[i]<a[i-1])break;
printf("%d\n",n-j);
return 0;
}

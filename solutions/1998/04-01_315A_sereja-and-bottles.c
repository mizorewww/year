/* Codeforces 315A - Sereja and Bottles
 * https://codeforces.com/problemset/problem/315/A
 * rating: 1400 | tags: brute force
 * source: accepted submission #3836229 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int an=0,n,y,i,j,k,x,a[1001],b[1001];
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d%d",&a[i],&b[i]);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if((a[i]==b[j])&&(i!=j))
{an++;
break;
}
}
}	
printf("%d\n",n-an);
return(0);
}

/* Codeforces 302A - Eugeny and Array
 * https://codeforces.com/problemset/problem/302/A
 * rating: 800 | tags: implementation
 * source: accepted submission #3678245 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int n,m,a[200000],i,x,y,p=0,q=0;
scanf("%d %d",&n,&m);
for(i=0;i<n;i++)
{scanf("%d",&a[i]);
if(a[i]==1)
{p++;}
else
{q++;}}
for(i=0;i<m;i++)
{scanf("%d %d",&x,&y);
if((y-x+1)%2==0)
{if(p>=(y-x+1)/2&&q>=(y-x+1)/2){
printf("1\n");}
else
{printf("0\n");}}
else
{printf("0\n");}
}
return 0;
}

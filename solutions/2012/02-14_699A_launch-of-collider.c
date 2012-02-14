/* Codeforces 699A - Launch of Collider
 * https://codeforces.com/problemset/problem/699/A
 * rating: 1000 | tags: implementation
 * source: accepted submission #20567518 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int n,min=1000000000,i,x=0;
scanf ("%d",&n);
int a[n];
char s[n+1];
scanf ("%s",&s);

for (i=0;i<n;i++)
scanf ("%d",&a[i]);

for (i=0;i<n-1;i++)
{if ((s[i]=='R')&&(s[i+1]=='L'))
{
x=(a[i+1]-a[i])/2;
if (x<min)
{min=x;}
}}
if (min==1000000000) printf("-1");
else printf("%d",min);

return 0;
}

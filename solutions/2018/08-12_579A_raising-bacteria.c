/* Codeforces 579A - Raising Bacteria
 * https://codeforces.com/problemset/problem/579/A
 * rating: 1000 | tags: bitmasks
 * source: accepted submission #13033418 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int x=0,y=0,n;
scanf("%d",&n);
while(n>1)
{
x=n%2;
if(x==1)
y++;
n=n/2;

}
if(n==1)
y++;
printf("%d\n",y);

return 0;
}

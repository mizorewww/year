/* Codeforces 268C - Beautiful Sets of Points
 * https://codeforces.com/problemset/problem/268/C
 * rating: 1500 | tags: constructive algorithms, implementation
 * source: accepted submission #3027562 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int i,min,n,m;
scanf("%d%d",&n,&m);
min=n;
if(m<min)min=m;
printf("%d\n",min+1);
for(i=0;i<=min;i++)
printf("%d %d\n",i,min-i);
return 0;
}

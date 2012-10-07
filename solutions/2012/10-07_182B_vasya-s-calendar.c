/* Codeforces 182B - Vasya's Calendar
 * https://codeforces.com/problemset/problem/182/B
 * rating: 1000 | tags: implementation
 * source: accepted submission #1621705 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int d,m,sum,a;
scanf("%d",&d);
scanf("%d",&m);
sum=0;
while(m--)
{
scanf("%d",&a);
if(m!=0)
sum=sum+d-a;
}
printf("%d",sum);

return 0;
}

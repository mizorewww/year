/* Codeforces 1605A - A.M. Deviation
 * https://codeforces.com/problemset/problem/1605/A
 * rating: 800 | tags: math, number theory
 * source: accepted submission #135156479 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{ int t;
scanf("%d",&t);
while(t--)
{
int a,b,c,s;
scanf("%d %d %d",&a,&b,&c);
s=a+b+c;
if(s%3==0)
printf("0\n");
else
printf("1\n");
}
}

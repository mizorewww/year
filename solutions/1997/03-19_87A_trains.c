/* Codeforces 87A - Trains
 * https://codeforces.com/problemset/problem/87/A
 * rating: 1500 | tags: implementation, math
 * source: accepted submission #20566414 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
long int a,b,x,y,n,m,t,gcd;
scanf("%ld%ld",&a,&b);
x=a;y=b;
if(a>b)
{
while(y)
{
t=y;
y=x%y;
x=t;
}
gcd=x;
m=a/gcd;
n=b/gcd;
if(n>(m-1))
printf("Dasha");
else if(n<(m-1))
printf("Masha");
else 
printf("Equal");
}
else
{
while(x)
{
t=x;
x=y%x;
y=t;
}
gcd=y;
m=a/gcd;
n=b/gcd;
if(m>(n-1))
printf("Masha");
else if(m<(n-1))
printf("Dasha");
else
printf("Equal");
}
return 0;
}

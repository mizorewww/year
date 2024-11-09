/* Codeforces 931B - World Cup
 * https://codeforces.com/problemset/problem/931/B
 * rating: 1200 | tags: constructive algorithms, implementation
 * source: accepted submission #35995003 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
 #include<string.h>
int main()
{
int n,a,b,p=0;
scanf("%d%d%d",&n,&a,&b);
for(;a!=b;)
{a=(a+1)/2;
b=(b+1)/2;
n=(n+1)/2;
p=p+1;
}
if(n==1)
printf("Final!");
else
printf("%d",p);

}

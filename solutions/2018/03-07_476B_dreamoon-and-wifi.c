/* Codeforces 476B - Dreamoon and WiFi
 * https://codeforces.com/problemset/problem/476/B
 * rating: 1300 | tags: bitmasks, brute force, combinatorics, dp, math, probabilities
 * source: accepted submission #8201134 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>
char a[20];
double f(int a,int b)
{
int i,j;
double d;
d=1;
for(i=1,j=a;i<=b;i++,j--)
d=d*j/i;
return d;
}
int main()
{
int jia,jian;
int i,max,min,wen,n,m;
double g;
jia=jian=max=min=wen=0;
scanf("%s",a);
for(i=0;a[i]!=0;i++)
{
if(a[i]=='+')
jia++;
else if(a[i]=='-')
jian++;
}

scanf("%s",a);
for(i=0;a[i]!=0;i++)
{
if(a[i]=='+')
max++;
else if(a[i]=='-')
min++;
else if(a[i]=='?')
wen++;
}
if(max>jia||min>jian)
printf("0.000000000000\n");
else
{
printf("%.12lf\n",pow(0.5,wen)*f(wen,jia-max));


}

return 0;
}

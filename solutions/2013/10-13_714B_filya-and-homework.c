/* Codeforces 714B - Filya and Homework
 * https://codeforces.com/problemset/problem/714/B
 * rating: 1200 | tags: implementation, sortings
 * source: accepted submission #20618484 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int c;
long int i,n;
scanf("%ld",&n);
long long int a[n],min,max;
long double com,r,s,avg;
scanf("%lld",&a[0]);
max=min=a[0];
for(i=1;i<n;i++)
{
scanf("%lld",&a[i]);
if(a[i]>max)
max=a[i];
if(a[i]<min)
min=a[i];
}
r=max;
s=min;
avg=(r+s)/2;
for(i=0;i<n;i++)
{
com=a[i];
if((com==avg)||(com==min)||(com==max))
c=0;
else
{
c=1;
break;
}
}
if(c)
printf("NO");
else 
printf("YES");
return 0;
}

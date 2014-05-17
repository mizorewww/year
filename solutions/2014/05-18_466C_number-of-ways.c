/* Codeforces 466C - Number of Ways
 * https://codeforces.com/problemset/problem/466/C
 * rating: 1700 | tags: binary search, brute force, data structures, dp, two pointers
 * source: accepted submission #7767811 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
long long a[500005];
long long aa[500005];
int main()
{
int n,i,j,b;
long long t,m,sum,max;
long long d;
sum=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&b);
sum+=b;
a[i]=sum;
}

if(sum%3!=0)
printf("0\n");
else if(sum!=0)
{
m=max=0;
d=sum/3;
for(i=0;i<n-1;i++)
if(a[i]==d)
m++;
else if(a[i]==2*d)
max+=m;

printf("%I64d\n",max);
}
else
{
m=max=0;
for(i=0;i<n-1;i++)
if(a[i]==0)
m++;
printf("%I64d\n",m*(m-1)/2);

}

return 0;
}

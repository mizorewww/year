/* Codeforces 676A - Nicholas and Permutation
 * https://codeforces.com/problemset/problem/676/A
 * rating: 800 | tags: constructive algorithms, implementation
 * source: accepted submission #19535526 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()

{

int n,i,t,min,max,a,b;

scanf("%d",&n);

for(i=1;i<=n;i++)

{

scanf("%d",&t);

if(t==1)

min=i;

if(t==n)

max=i;

}

a=min<max?min:max;

b=min>max?min:max;

t=a-1>n-b?1:n;

if(t==1)

printf("%d",b-t);

else

printf("%d",t-a);

}

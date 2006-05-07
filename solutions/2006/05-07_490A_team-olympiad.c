/* Codeforces 490A - Team Olympiad
 * https://codeforces.com/problemset/problem/490/A
 * rating: 800 | tags: greedy, implementation, sortings
 * source: accepted submission #18987742 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()

{

int n,a=0,b=0,c=0,min,i;

scanf("%d",&n);

int d[n],x[n],y[n],z[n];

for(i=0;i<n;i++)

{

scanf("%d",&d[i]);

if(d[i]==1)

x[a++]=i+1;

else if(d[i]==2)

y[b++]=i+1;

else

z[c++]=i+1;

}

min=a<b?a<c?a:c:b<c?b:c;

printf("%d\n",min);

for(i=0;i<min;i++)

printf("%d %d %d\n",x[i],y[i],z[i]);

}

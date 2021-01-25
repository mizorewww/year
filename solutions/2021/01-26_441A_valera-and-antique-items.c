/* Codeforces 441A - Valera and Antique Items
 * https://codeforces.com/problemset/problem/441/A
 * rating: 1000 | tags: implementation
 * source: accepted submission #19468899 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()

{

int n,v,i,t,j,k,c=0,min;

scanf("%d%d",&n,&v);

int a[n+1];

for(i=1;i<=n;i++)

{

min=100000000;

scanf("%d",&k);

for(j=1;j<=k;j++)

{

scanf("%d",&t);

if(t<min)

min=t;

}

if(v>min)

a[c++]=i;	

}

printf("%d\n",c);

for(i=0;i<c;i++)

printf("%d ",a[i]);

}

/* Codeforces 507A - Amr and Music
 * https://codeforces.com/problemset/problem/507/A
 * rating: 1000 | tags: greedy, implementation, sortings
 * source: accepted submission #9523344 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10010],i,j,k,n,temp,m[10000],min=32000,b=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	b=0;
	for(i=0;i<n;i++)
	{
	 min=32000;
	for(j=0;j<n;j++)
	{
	if(a[j]<min)
	{
	   min=a[j];
	   temp=j;
	   }
	 }
	  if(k-a[temp]>=0){
	   m[b++]=temp+1;
	   k=k-a[temp];
	   a[temp]=32000;}
	   else 
	   break;
	}
	  printf("%d\n",b);
	  for(i=0;i<b;i++)
	  printf("%d\t",m[i]);
	  printf("\n");
	  return 0;
}

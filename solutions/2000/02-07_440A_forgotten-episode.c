/* Codeforces 440A - Forgotten Episode
 * https://codeforces.com/problemset/problem/440/A
 * rating: 800 | tags: implementation
 * source: accepted submission #6790656 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
 
int a[1000005];
 
int main() {
 
	int n,temp,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	  scanf("%d",&temp);
	  a[temp]=1;
 
	}
	for(i=1;i<=n;i++)
	{
	  if(a[i]!=1)  break;
	}
	printf("%d",i);
	return 0;
}

/* Codeforces 454B - Little Pony and Sort by Shift
 * https://codeforces.com/problemset/problem/454/B
 * rating: 1200 | tags: implementation
 * source: accepted submission #7316295 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int main(void) 
{
	int n,i,a,b,pos;
	int c=0,first;
	scanf("%d",&n);
	scanf("%d",&first);
	a=first;
	for(i=2;i<=n;i++)
	{
	scanf("%d",&b);
	if(a>b)
	{c++;pos=i;}
	a=b;
	}
	if(c==0)
	printf("0");
	else if(c==1&&b<=first)
	printf("%d",n-pos+1);
	else
	printf("-1");
	return 0;
}

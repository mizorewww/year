/* Codeforces 353C - Find Maximum
 * https://codeforces.com/problemset/problem/353/C
 * rating: 1600 | tags: implementation, math, number theory
 * source: accepted submission #4734424 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#define Max(a,b) ((a)<(b))?(b):(a)

int ar[100500];
char as[100500];

int main()
{
	int i, n, top=0, ara=0, res;
	char ch;
	
	scanf(" %d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	
	for(i=0;i<n;i++)
	{
		scanf(" %c",&as[i]);
		if(as[i]=='1') top+=ar[i];
	}
	res=top;
	for(i=0;i<n;i++)
	{
		if(as[i]=='0') ara+=ar[i];
		else
			res=Max( res , top-ar[i]+ara );
	}
	printf("%d\n",res);
	
	return 0;
}

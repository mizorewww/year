/* Codeforces 831A - Unimodal Array
 * https://codeforces.com/problemset/problem/831/A
 * rating: 1000 | tags: implementation
 * source: accepted submission #28523010 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int main ()
{
	int a[1000],x,i,l,c;
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=x;i++)
	{
		if(a[i]>a[i-1])
			l=1;
		if(a[i]==a[i-1])
			l=2;
		if(a[i]<a[i-1])
			l=3;
			
		if(l<c)
		{
			printf("NO");
			return 0;

		}
			c=l;
		
	}
				printf("YES");

}

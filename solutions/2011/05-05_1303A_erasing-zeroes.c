/* Codeforces 1303A - Erasing Zeroes
 * https://codeforces.com/problemset/problem/1303/A
 * rating: 800 | tags: implementation, strings
 * source: accepted submission #70877560 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int d,a,b=0,c,sum[100];
	char s;
	scanf("%d%",&a);
	for(;b<a;b++)
	{
		sum[b]=0;
		d=0;
		c=0;
		while(1)
		{
		scanf("%c",&s);
			if(s=='\n')
			break;
			d++;
			if(s=='1')
			{
				if(c!=0)
				sum[b]+=d-c-1;
				c=d;
			} 
			
		}

	}
	for(b=0;b<a;b++)
	printf("%d\n",sum[b]);
	return 0;
 }

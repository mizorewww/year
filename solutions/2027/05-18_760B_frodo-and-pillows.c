/* Codeforces 760B - Frodo and pillows
 * https://codeforces.com/problemset/problem/760/B
 * rating: 1500 | tags: binary search, greedy
 * source: accepted submission #24045568 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n,m,i=1,j,k,d,c=1,l;
	scanf("%d%d%d",&n,&m,&k);
	l=n-k;
	m-=n;
	while(m>=i)
	{
		c++;
		m-=i;
		if(k-1>0)
		{
			k--;
			i++;
		}
		if(l>0)
		{
			l--;
			i++;
		}
	}
	printf("%d",c);
}

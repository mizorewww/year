/* Codeforces 1469B - Red and Blue
 * https://codeforces.com/problemset/problem/1469/B
 * rating: 1000 | tags: dp, greedy
 * source: accepted submission #102572125 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef long long (ll);

int main()
{
	ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,L,R;
	scanf("%lli",&a);
	for(;a;a--)
	{
		scanf("%lli",&b);
		for(c=e=0;b;b--)
		{
			scanf("%lli",&d);
			c+=d;
			if(c>e)e=c;
		}
		scanf("%lli",&b);
		for(c=f=0;b;b--)
		{
			scanf("%lli",&d);
			c+=d;
			if(c>f)f=c;
		}
		printf("%lli",e+f);
		printf("\n");
	}
	return 0;
}

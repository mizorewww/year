/* Codeforces 893B - Beautiful Divisors
 * https://codeforces.com/problemset/problem/893/B
 * rating: 1000 | tags: brute force, implementation
 * source: accepted submission #32589005 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include<math.h>
int main(void) 
{
	int n,i=0,k=1,r;
	scanf("%d",&n);
	while(i<=n)
	{
		i=(pow(2,k)-1)*(pow(2,k-1));
		
		if(n%i==0)
		{
		   r=i;	
		}
		  
		k++;
	}
	printf("%d",r);
	
	return 0;
}

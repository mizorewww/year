/* Codeforces 1296A - Array with Odd Sum
 * https://codeforces.com/problemset/problem/1296/A
 * rating: 800 | tags: math
 * source: accepted submission #70254718 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main()
{
	int N,n,i,x,odd;
	scanf("%d",&N);
	while(N--)
	{
		odd=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x%2!=0)
				odd++;
		}
		if(odd!=0&&(odd%2!=0||n!=odd))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

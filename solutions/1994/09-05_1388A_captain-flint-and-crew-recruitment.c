/* Codeforces 1388A - Captain Flint and Crew Recruitment
 * https://codeforces.com/problemset/problem/1388/A
 * rating: 800 | tags: brute force, greedy, math, number theory
 * source: accepted submission #88480071 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n>30)
		{
			printf("Yes\n");
			printf("6 10 ");
			int st=n-30;
			if(st==6||st==10||st==14)
			printf("15 %d\n",n-31);
			else
			printf("14 %d\n",n-30);
		}
		else
		printf("No\n");
	}
}

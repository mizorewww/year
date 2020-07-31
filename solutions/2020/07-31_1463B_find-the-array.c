/* Codeforces 1463B - Find The Array
 * https://codeforces.com/problemset/problem/1463/B
 * rating: 1400 | tags: bitmasks, constructive algorithms, greedy
 * source: accepted submission #101555964 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int q(int a)
{
	int i=1;
	while(i<=a) i*=2;
	if(i==1) return 1;
	else return i/2;
}
int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int n;
		scanf("%d",&n);
		int s[n];
		for(int i=0;i<n;i++)
		{
		    scanf("%d",&s[i]);
		    printf("%d ",q(s[i]));
		}
		printf("\n");
	}
	return 0;
}

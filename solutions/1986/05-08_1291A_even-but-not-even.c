/* Codeforces 1291A - Even But Not Even
 * https://codeforces.com/problemset/problem/1291/A
 * rating: 900 | tags: greedy, math, strings
 * source: accepted submission #70052052 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main()
{
	int i,j,k,n,t,s,s1,z;
	scanf("%d",&t);
	for(int z1=0;z1<t;z1++)
	{
		scanf("%d",&n);
		char a[n+1];s=0,s1=0;z=0;
		for(i=0;i<n;i++)
		{
		scanf(" %c",&a[i]);
		j=a[i]-48;
		if(j%2!=0&&z<2)
		{
			z++;
			s1=s1*10+j;
		}
		}
		if(z<2)
		printf("-1\n");
		else
		printf("%d\n",s1);
	}
	
}

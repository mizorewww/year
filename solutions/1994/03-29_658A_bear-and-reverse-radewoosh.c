/* Codeforces 658A - Bear and Reverse Radewoosh
 * https://codeforces.com/problemset/problem/658/A
 * rating: 800 | tags: implementation
 * source: accepted submission #16995336 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	int p[n],t[n];
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&t[i]);
	long long int x=0,suml=0,sumr=0;
	for(int i=0;i<n;i++)
	{
		x+=t[i];
		if((p[i]-c*x)>0)
			suml+=(p[i]-c*x);
	}
	x=0;
	for(int i=n-1;i>=0;i--)
	{
		x+=t[i];
		if((p[i]-c*x)>0)
			sumr+=(p[i]-c*x);
	}
	if(suml>sumr)
		printf("Limak\n");
	else if(sumr>suml)
		printf("Radewoosh\n");
	else
		printf("Tie\n");
	return 0;
}

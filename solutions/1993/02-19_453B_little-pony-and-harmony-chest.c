/* Codeforces 453B - Little Pony and Harmony Chest
 * https://codeforces.com/problemset/problem/453/B
 * rating: 2000 | tags: bitmasks, brute force, dp
 * source: accepted submission #7317204 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define me(x) memset(x,0,sizeof(x))
long n,a[105],p[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
long dp[105][65536],ch[105][65536],va[60];
long ab(long x)
{
	return x>0?x:-x;
}
long an[105];
int main()
{
	long i,j,k;
	scanf("%ld",&n);
	for (i=1;i<=n;i++) scanf("%ld",&a[i]);
	me(dp[0]);
	for (i=1;i<=n;i++) for (j=0;j<65536;j++) dp[i][j]=99999999;
	for (j=1;j<=58;j++)
	{
		va[j]=0;
		for (i=0;i<16;i++) if (j%p[i]==0) va[j]+=1<<i;
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<65536;j++)
		for (k=1;k<=58;k++) if (!(j&va[k])&&dp[i+1][j|va[k]]>dp[i][j]+ab(k-a[i+1]))
		{
			dp[i+1][j|va[k]]=dp[i][j]+ab(k-a[i+1]);
			ch[i+1][j|va[k]]=k;
		}
	}
	j=65535;
	for (i=n;i>0;i--)
	{
		an[i]=ch[i][j];
		j^=va[ch[i][j]];
	}
	for (i=1;i<=n;i++)
	{
		printf("%ld",an[i]);
		if (i!=n) printf(" ");
	}
	return 0;
}

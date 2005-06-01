/* Codeforces 1363B - Subsequence Hate
 * https://codeforces.com/problemset/problem/1363/B
 * rating: 1400 | tags: implementation, strings
 * source: accepted submission #82109012 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,k,n,t,z;
	scanf("%d",&t);
	for(int z1=0;z1<t;z1++)
	{
		char s[1001];
		k=0;z=0;
		int ans=10000;
		scanf("%s",s);
		n=strlen(s);
		
		int a[n+1],b[n+1];
		for(i=0;i<n;i++)
		{
			if(s[i]=='1')
			k++;
			else
			z++;
			a[i+1]=k;
			b[i+1]=z;
		}
		a[0]=0;
		b[0]=0;
		for(i=1;i<=n;i++)
		{
			k=b[n]-b[i-1];
			k=k+a[i-1];
			if(k<ans)
			ans=k;
		}
		for(i=1;i<=n;i++)
		{
			k=a[n]-a[i-1];
			k=k+b[i-1];
			if(k<ans)
			ans=k;
		}
		printf("%d\n",ans);
	}
}

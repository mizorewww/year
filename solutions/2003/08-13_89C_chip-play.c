/* Codeforces 89C - Chip Play
 * https://codeforces.com/problemset/problem/89/C
 * rating: 2300 | tags: brute force, data structures, implementation
 * source: accepted submission #491098 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
long lal[5005]={0},lar[5005]={0},lau[5005]={0},lad[5005]={0},lastl[5005]={0},lastr[5005]={0},lastu[5005]={0},lastd[5005]={0};
long num[5005][5005]={0};
char c[5005][5005]={'\0'};
int main()
{
	long i,j,n,m,x,y,tx,ty,ans=0,count,tot=0,ansi,la;
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	scanf("%ld %ld\n",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%c",&c[i][j]);
			num[i][j]=++tot;
		}
		scanf("\n");
	}
	for(i=1;i<=n;i++)
		for(j=1,la=0;j<=m;j++)
		{
			lastl[num[i][j]]=la;
			if(c[i][j]!='.')
				la=j;
		}
	for(i=1;i<=n;i++)
		for(j=m,la=0;j>=1;j--)
		{
			lastr[num[i][j]]=la;
			if(c[i][j]!='.')
				la=j;
		}
	for(j=1;j<=m;j++)
		for(i=1,la=0;i<=n;i++)
		{
			lastu[num[i][j]]=la;
			if(c[i][j]!='.')
				la=i;
		}
	for(j=1;j<=m;j++)
		for(i=n,la=0;i>=1;i--)
		{
			lastd[num[i][j]]=la;
			if(c[i][j]!='.')
				la=i;
		}
	for(x=1;x<=n;x++)
		for(y=1;y<=m;y++)
		if(c[x][y]!='.')
		{
			count=0;
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
				{
					lal[num[i][j]]=lastl[num[i][j]]; lar[num[i][j]]=lastr[num[i][j]];
					lau[num[i][j]]=lastu[num[i][j]]; lad[num[i][j]]=lastd[num[i][j]];
				}
			tx=x; ty=y;
			if(tx==3 && ty==3)
				i=1;
			while(1)
			{
				lal[num[tx][lar[num[tx][ty]]]]=lal[num[tx][ty]];
				lar[num[tx][lal[num[tx][ty]]]]=lar[num[tx][ty]];
				lau[num[lad[num[tx][ty]]][ty]]=lau[num[tx][ty]];
				lad[num[lau[num[tx][ty]]][ty]]=lad[num[tx][ty]];
				count++;
				if(c[tx][ty]=='L')
				{
					if(lal[num[tx][ty]]==0)
						break;
					ty=lal[num[tx][ty]];
				}
				else if(c[tx][ty]=='R')
				{
					if(lar[num[tx][ty]]==0)
						break;
					ty=lar[num[tx][ty]];
				}
				else if(c[tx][ty]=='U')
				{
					if(lau[num[tx][ty]]==0)
						break;
					tx=lau[num[tx][ty]];
				}
				else if(c[tx][ty]=='D')
				{
					if(lad[num[tx][ty]]==0)
						break;
					tx=lad[num[tx][ty]];
				}
			}
			if(count>ans)
			{
				ans=count;
				ansi=1;
			}
			else if(count==ans)
				ansi++;
		}
	printf("%ld %ld\n",ans,ansi);
	return 0;
}

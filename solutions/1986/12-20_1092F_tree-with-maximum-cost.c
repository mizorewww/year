/* Codeforces 1092F - Tree with Maximum Cost
 * https://codeforces.com/problemset/problem/1092/F
 * rating: 1900 | tags: dfs and similar, dp, trees
 * source: accepted submission #47223477 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int n,m,i;
int x1[400010],y1[400010],y[400010],d[400010],w[400010];
int l[400010],r[400010];
long long final;
long long ver[400010],ans[400010],a[400010],fa[400010],dist[400010];
void build_tree(int i)
{
	int j,u;
	ver[i]=a[i];
	for(j=l[i];j<=r[i];j++)
	{
		u=y[j];
		if(ver[u]==0)
		{
			fa[u]=i;
			build_tree(u);
			ver[i]+=ver[u];
		}
	}
}
void solve(int i)
{
	int j,u;
	for(j=l[i];j<=r[i];j++)
	{
		u=y[j];
		if(fa[u]==i)
		{
			ans[u]=ans[i]+(ver[1]-2*ver[u]);
			if(ans[u]>final)final=ans[u];
			solve(u);
		}
	}
}
void calcu(int i)
{
	int j,u;
	for(j=l[i];j<=r[i];j++)
	{
		u=y[j];
		if(fa[u]==i)
		{
			dist[u]=dist[i]+1;
			ans[1]=ans[1]+dist[u]*a[u];
			calcu(u);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	m=n-1;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x1[i],&y1[i]);
		d[x1[i]]++;
		d[y1[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=r[i-1]+d[i];
	}
	for(i=1;i<=m;i++)
	{
		y[l[x1[i]]+w[x1[i]]]=y1[i];
		w[x1[i]]++;
		y[l[y1[i]]+w[y1[i]]]=x1[i];
		w[y1[i]]++;
	}
    build_tree(1);
    calcu(1);
    final=ans[1];
    solve(1);
	printf("%I64d\n",final);
	//for(i=1;i<=n;i++)printf("%d ",ver[i]);
	//printf("\n");
	//for(i=1;i<=n;i++)printf("%d ",dist[i]);
	//printf("\n");
	//for(i=1;i<=n;i++)printf("%I64d ",ans[i]);
	//printf("\n");
}

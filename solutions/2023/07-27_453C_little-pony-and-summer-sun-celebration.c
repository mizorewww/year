/* Codeforces 453C - Little Pony and Summer Sun Celebration
 * https://codeforces.com/problemset/problem/453/C
 * rating: 2200 | tags: constructive algorithms, dfs and similar, graphs
 * source: accepted submission #7314376 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define me(x) memset(x,0,sizeof(x))
#define maxm 100005
#define maxn 100005
long n,m;
struct edge
{
	long to,nx;
};
struct edge es[maxm*2];
long st[maxn]={0},en=0,xx[maxn],nu=0,fail=0,now;
long an[maxn*4],tot=0;
void add(long x,long y)
{
	struct edge e;
	e.to=y;
	e.nx=st[x];
	es[++en]=e;
	st[x]=en;
}
long que[maxn],ss,ee,last[maxn],vis[maxn]={0},nv=0;
long bfs(long x)
{
	long i,j;
	nv++;
	ss=ee=0; que[0]=x;
	while(ss<=ee)
	{
		j=que[ss++];
		for (i=st[j];i;i=es[i].nx) if (vis[es[i].to]<nv)
		{
			vis[es[i].to]=nv;
			last[es[i].to]=j;
			que[++ee]=es[i].to;
			if (xx[es[i].to]) return es[i].to;
		}
	}
	return 0;
}
void addan(long x)
{
	an[++tot]=x;
}
long od[maxn],on;
void getan(long x)
{
	long i;
	on=0;
	for (i=x;i!=now;i=last[i]) od[on++]=i;
	od[on++]=now;
	for (i=on-1;i>0;)
	{
		if (i==1)
		{
			addan(x);
			now=x;
			return;
		}
		if (i==2)
		{
			addan(od[1]);
			addan(x);
			addan(od[1]);
			now=od[1];
			return;
		}
		addan(od[i-1]);
		addan(od[i-2]);
		addan(od[i-1]);
		addan(od[i-2]);
		i-=2;
	}
}
void check()
{
	long i=bfs(now);
	if (!i)
	{
		fail=1;
		nu=0;
	}
	else
	{
		getan(i);
		xx[i]=0; nu--;
	}
}
int main()
{
	long i,u,v;
	scanf("%ld %ld",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%ld %ld",&u,&v);
		add(u,v); add(v,u);
	}
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&xx[i]);
		nu+=xx[i];
	}
	if (nu==0)
	{
		printf("0");
		return 0;
	}
	for (i=1;i<=n;i++) if (xx[i]) break;
	xx[i]=0; nu--; now=i; an[++tot]=i;
	while(nu) check();
	if (fail) printf("-1");
	else
	{
		printf("%ld\n",tot);
		for (i=1;i<=tot;i++) printf("%ld ",an[i]);
	}
	return 0;
}

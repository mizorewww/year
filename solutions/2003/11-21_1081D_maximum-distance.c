/* Codeforces 1081D - Maximum Distance
 * https://codeforces.com/problemset/problem/1081/D
 * rating: 1800 | tags: dsu, graphs, shortest paths, sortings
 * source: accepted submission #47129399 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int n,m,k,i,xx,min,max,mid;
int q[200010],v1[200010],d[200010],w[200010],x1[200010],y1[200010],z1[200010],y[200010],z[200010];
int v2[200010],l[200010],r[200010];
int check(int mid)
{
    int i,j,u,v,h,t,tot;
	h=0;t=1;q[1]=xx;
	for(i=1;i<=n;i++)v2[i]=0;
	v2[xx]=1;tot=1;
	while(h<t)
	{
		h++;
		u=q[h];
		for(j=l[u];j<=r[u];j++)
		{
			if(z[j]<=mid)
			{
				v=y[j];
				if(v2[v]==0)
				{
					t++;
					q[t]=v;
					v2[v]=1;
					if(v1[v]==1)tot++;
				}
			}
		}
	}
	if(tot==k)return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d", &n,&m,&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&xx);
		v1[xx]=1;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x1[i],&y1[i],&z1[i]);
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
		z[l[x1[i]]+w[x1[i]]]=z1[i];
		w[x1[i]]++;
		y[l[y1[i]]+w[y1[i]]]=x1[i];
		z[l[y1[i]]+w[y1[i]]]=z1[i];
		w[y1[i]]++;
	}
	min=0;max=1000000010;
	while(min<max)
	{
		mid=(min+max)/2;
		if(check(mid)==1)max=mid;else min=mid+1;
	}
	for(i=0;i<k;i++)printf("%d ",min);
}

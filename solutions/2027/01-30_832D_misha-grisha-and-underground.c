/* Codeforces 832D - Misha, Grisha and Underground
 * https://codeforces.com/problemset/problem/832/D
 * rating: 1900 | tags: dfs and similar, graphs, trees
 * source: accepted submission #28848481 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxn 100000
#define maxm 100000

struct node
{
    long d,value;
    struct node *next;
}*point[maxn+1],*info[maxn+1];
long fa[maxn+1],dist[maxn+1],result[maxm+1],u[maxm*3+1],v[maxm*3+1];
bool use[maxn+1];

long getfather(long d)
{
    if (fa[d]==d)
        return d;
    fa[d]=getfather(fa[d]);
    return fa[d];
}

void tarjan(long d)
{
    struct node *p;
    use[d]=true;
    p=point[d];
    while (p)
    {
        if (!use[p->d])
        {
        	dist[p->d]=dist[d]+p->value;
            tarjan(p->d);
            fa[p->d]=d;
        }
        p=p->next;
    }

    p=info[d];
    while (p)
    {
        if (use[p->d])
            v[p->value]=getfather(p->d);
        p=p->next;
    }
}

int main()
{
    long i,j,x,y,z,n,m;
    long value,value1,value2,value3,valuemin;
    struct node *p;

    scanf("%ld%ld",&n,&m);
    for (i=1;i<=n;i++)
        point[i]=NULL;
    for (i=1;i<n;i++)
    {
        scanf("%ld",&x);
        p=(struct node *) malloc (sizeof(struct node));
        p->d=x;
        p->value=1;
        p->next=point[i+1];
        point[i+1]=p;

        p=(struct node *) malloc (sizeof(struct node));
        p->d=i+1;
        p->value=1;
        p->next=point[x];
        point[x]=p;
    }

    for (i=1;i<=n;i++)
        info[i]=NULL;

    for (i=1,j=0;i<=m;i++)
    {
        scanf("%ld%ld%ld",&x,&y,&z);
        u[j+1]=x; u[j+2]=y; u[j+3]=z;
        p=(struct node *) malloc (sizeof(struct node));
        p->d=y;
        p->value=++j;
        p->next=info[x];
        info[x]=p;

        p=(struct node *) malloc (sizeof(struct node));
        p->d=x;
        p->value=j;
        p->next=info[y];
        info[y]=p;

        p=(struct node *) malloc (sizeof(struct node));
        p->d=z;
        p->value=++j;
        p->next=info[x];
        info[x]=p;

        p=(struct node *) malloc (sizeof(struct node));
        p->d=x;
        p->value=j;
        p->next=info[z];
        info[z]=p;

        p=(struct node *) malloc (sizeof(struct node));
        p->d=z;
        p->value=++j;
        p->next=info[y];
        info[y]=p;

        p=(struct node *) malloc (sizeof(struct node));
        p->d=y;
        p->value=j;
        p->next=info[z];
        info[z]=p;
    }
    dist[1]=0;
    for (i=1;i<=n;i++)
        use[i]=false;
    for (i=1;i<=n;i++)
        fa[i]=i;
    tarjan(1);
    for (i=1,j=0;i<=m;i++,j+=3)
        {
            value=dist[u[j+1]]+dist[u[j+2]]+dist[u[j+3]]-dist[v[j+1]]-dist[v[j+2]]-dist[v[j+3]];
            value1=dist[u[j+1]]+dist[u[j+2]]-dist[v[j+1]]*2;
            value2=dist[u[j+1]]+dist[u[j+3]]-dist[v[j+2]]*2;
            value3=dist[u[j+2]]+dist[u[j+3]]-dist[v[j+3]]*2;

            if (value1<value2)
            {
                if (value1<value3)
                    valuemin=value1;
                else
                    valuemin=value3;
            }
            else
            {
                if (value2<value3)
                    valuemin=value2;
                else
                    valuemin=value3;
            }
            printf("%ld\n",value1+value2+value3-valuemin-value+1);
        }

    return 0;
}

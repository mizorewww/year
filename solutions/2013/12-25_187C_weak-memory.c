/* Codeforces 187C - Weak Memory
 * https://codeforces.com/problemset/problem/187/C
 * rating: 2000 | tags: dfs and similar, dsu
 * source: accepted submission #18950943 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

#include <string.h>

int n,m,k,S,T;

int e[400010][2],p[100010];

int q[100010],dis[100010];

int root[100010];

void adde(int sn,int fn,int id)

{

    e[id][0] = fn; e[id][1] = p[sn]; p[sn] = id;

}

int findroot(int nod)

{

    if(root[nod] != nod) root[nod] = findroot(root[nod]);

    return root[nod];

}

short bfs(int lim)

{

    int i,sn,fn,rs,rf;

    int head = 1,tail = k+2;

    memset(dis,0,sizeof(dis));

    for(i=1;i<=n;i++) root[i] = i;

    for(i=1;i<=k+1;i++) dis[q[i]] = 1;

    while(head<tail)

    {

        sn = q[head++]; rs = findroot(sn);

        for(i=p[sn];i;i=e[i][1])

        {

            fn = e[i][0]; rf = findroot(fn);

            if(rs == rf) continue;

            if(!dis[fn])

            {

                root[rf] = rs;

                dis[fn] = dis[sn]+1;

                q[tail++] = fn;

            }

            else if(dis[sn]+dis[fn]-1<=lim) root[rf] = rs;

        }

    }

    return findroot(S) == findroot(T);

}

int work()

{

    int head = 1,tail = n,mid;

    while(head<tail)

    {

        mid = (head+tail)>>1;

        if(bfs(mid)) tail = mid;

        else head = mid+1;

    }

    return head==n?-1:head;

}

int main()

{

    int i,sn,fn;

    scanf("%d%d%d",&n,&m,&k);

    for(i=1;i<=k;i++) scanf("%d",&q[i]);

    for(i=1;i<=m;i++)

    {

        scanf("%d%d",&sn,&fn);

        adde(sn,fn,i<<1); adde(fn,sn,i<<1|1);

    }

    scanf("%d%d",&S,&T);

    q[k+1] = T;

    printf("%d",work());

    return 0;

}

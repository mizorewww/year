/* Codeforces 498C - Array and Operations
 * https://codeforces.com/problemset/problem/498/C
 * rating: 2100 | tags: flows, graph matchings, number theory
 * source: accepted submission #18997731 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

#define INF 9999999

#define S 0

#define T 2000

int n,m,num[110];

int ncnt,fac[110][15][2];

int pcnt,prime[40010];

short flag[40010];

int tot = 1,e[100010][3],p[2010];

int dis[2010],from[2010],cur[2010],gap[2010];

void adde(int sn,int fn,int val)

{

    e[++tot][0] = fn; e[tot][1] = val; e[tot][2] = p[sn]; p[sn] = cur[sn] = tot;

    e[++tot][0] = sn; e[tot][1] = 0; e[tot][2] = p[fn]; p[fn] = cur[fn] = tot;

}

void div(int id,int x)

{

    int i,j,cnt;

    for(i=1,j=0;i<=pcnt&&x>1;i++) if(x%prime[i] == 0)

    {

        cnt = 0;

        while(x%prime[i] == 0) { x/= prime[i]; cnt++;}

        fac[id][++j][0] = prime[i];

        fac[id][j][1] = ++ncnt;

        if(id&1) adde(id,ncnt,cnt);

        else adde(ncnt,id,cnt);

    }

    if(x>1)

    {

        fac[id][++j][0] = x;

        fac[id][j][1] = ++ncnt;

        if(id&1) adde(id,ncnt,1);

        else adde(ncnt,id,1);

    }

}

int sap()

{

    int i,mmin,sn = S,flow = INF,ret = 0;

    gap[0] = ncnt+2;

    while(dis[S] <= T)

    {

        for(i=cur[sn];i;i=e[i][2]) if(e[i][1]>0 && dis[sn]==dis[e[i][0]]+1) break;

        cur[sn] = i;

        if(i)

        {

            sn = e[i][0]; from[sn] = i;

            flow = flow<e[i][1]?flow:e[i][1];

            if(sn != T) continue;

            ret += flow;

            for(;sn!=S;sn=e[from[sn]^1][0]) { e[from[sn]][1] -= flow; e[from[sn]^1][1] += flow;}

            flow = INF;

        }

        else

        {

            if(--gap[dis[sn]] == 0) break;

            cur[sn] = p[sn]; mmin = T+3;

            for(i=p[sn];i;i=e[i][2]) if(e[i][1]>0) mmin = mmin<dis[e[i][0]]?mmin:dis[e[i][0]];

            gap[dis[sn] = mmin+1]++;

            if(sn != S) sn = e[from[sn]^1][0];

        }

    }

    return ret;

}

int main()

{

    int i,j,sn,fn;

    for(i=2;i<=200;i++) if(!flag[i]) for(j=i<<1;j<=40000;j+=i) flag[j] = 1;

    for(i=2;i<=40000;i++) if(!flag[i]) prime[++pcnt] = i;

    

    scanf("%d%d",&n,&m); ncnt = n;

    for(i=1;i<=n;i++)

    {

        scanf("%d",&num[i]);

        div(i,num[i]);

        if(i&1) adde(S,i,INF);

        else adde(i,T,INF);

    }

    while(m--)

    {

        scanf("%d%d",&sn,&fn);

        if(fn&1) { i = sn; sn = fn; fn = i;}

        for(i=1;fac[sn][i][0];i++) for(j=1;fac[fn][j][0];j++) if(fac[sn][i][0] == fac[fn][j][0])

        {

            adde(fac[sn][i][1],fac[fn][j][1],INF);

            break;

        }

    }

    printf("%d",sap());

    return 0;

}

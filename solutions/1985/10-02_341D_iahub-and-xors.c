/* Codeforces 341D - Iahub and Xors
 * https://codeforces.com/problemset/problem/341/D
 * rating: 2500 | tags: data structures
 * source: accepted submission #20750010 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>



int n,q;



int oo[1010][1010],oe[1010][1010],eo[1010][1010],ee[1010][1010];



void add(int tree[1010][1010],int x,int y,int v)

{

    int i,j;

    for(i=x;i<=n;i+=i&(-i)) for(j=y;j<=n;j+=j&(-j)) tree[i][j] ^= v;

}



void update(int x,int y,int v)

{

    if((x&1) && (y&1)) add(oo,x,y,v);

    if((x&1) && !(y&1)) add(oe,x,y,v);

    if(!(x&1) && (y&1)) add(eo,x,y,v);

    if(!(x&1) && !(y&1)) add(ee,x,y,v);

}



int query(int tree[1010][1010],int x,int y)

{

    int i,j,ret = 0;

    for(i=x;i;i-=i&(-i)) for(j=y;j;j-=j&(-j)) ret ^= tree[i][j];

    return ret;

}



int ask(int x,int y)

{

    if((x&1) && (y&1)) return query(oo,x,y);

    if((x&1) && !(y&1)) return query(oe,x,y);

    if(!(x&1) && (y&1)) return query(eo,x,y);

    if(!(x&1) && !(y&1)) return query(ee,x,y);

}



int main()

{

    int op,xa,ya,xb,yb,v;

    scanf("%d%d",&n,&q);

    while(q--)

    {

        scanf("%d%d%d%d%d",&op,&xa,&ya,&xb,&yb);

        if(op == 1)

            printf("%d\n",ask(xa-1,ya-1)^ask(xa-1,yb)^ask(xb,ya-1)^ask(xb,yb));

        else

        {

            scanf("%d",&v);

            update(xb+1,yb+1,v); update(xa,ya,v);

            update(xa,yb+1,v); update(xb+1,ya,v);

        }

    }

    return 0;

}

/* Codeforces 1187C - Vasya And Array
 * https://codeforces.com/problemset/problem/1187/C
 * rating: 1800 | tags: constructive algorithms, greedy, implementation
 * source: accepted submission #56330980 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long m, k, l, t, i, j, k, q, a[2000][2], c[1000][2], d, x, y, b, g, w[2000], e;
char s[1000000];


int war(const void* aa, const void* bb)
{
    return(*(long long*)aa-*(long long*)bb);
}
/*
long long bins(long long p, long long k, long long s)
{
    if(a[(p+k)/2]>=s && a[(p+k)/2-1]<s)return((p+k)/2);
    if(a[(p+k)/2]<s)return(bins((p+k)/2+1,k,s));
    return(bins(p,(p+k)/2-1,s));
}*/

int main()
{
    scanf("%I64d%I64d", &l, &t);
    b=0;

    for(i=0; i<l; i++)
    {
        a[i][0]=i;
        a[i][1]=i;
    }

    for(j=0; j<t; j++)
    {
        scanf("%I64d%I64d%I64d", &q, &x, &y);
        if(q==0)
        {
            c[b][0]=x-1;
            c[b][1]=y-1;
            b++;
        }
        else
        {
            x=a[x-1][0];
            y=a[y-1][1];
            for(i=x; i<=y; i++)
            {
                a[i][0]=x;
                a[i][1]=y;
            }
        }
    }
    for(i=0; i<b; i++)
    {
        x=c[i][0];
        y=c[i][1];
        if(a[x][1]>=y)
        {
            printf("NO\n");
            return(0);
        }
        w[a[x][1]+1]=-1;
    }
    w[0]=2000;
    printf("YES\n2000 ");
    for(i=1; i<l; i++)
    {
        w[i]+=w[i-1];
        printf("%I64d ", w[i]);
    }

    return 0;
}

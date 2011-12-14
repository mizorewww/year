/* Codeforces 978C - Letters
 * https://codeforces.com/problemset/problem/978/C
 * rating: 1000 | tags: binary search, implementation, two pointers
 * source: accepted submission #38169826 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int n,m,x=0;
long long a[200005],k,tot=0;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%I64d",&k);
        while(k>tot)
        tot+=a[++x];
        printf("%d %I64d\n",x,k-(tot-a[x]));
    }
}

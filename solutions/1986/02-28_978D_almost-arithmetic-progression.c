/* Codeforces 978D - Almost Arithmetic Progression
 * https://codeforces.com/problemset/problem/978/D
 * rating: 1500 | tags: brute force, implementation, math
 * source: accepted submission #38177928 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int n,ans=123456789,countt;
long long a[100005],dif,ucit;
long long ab(long long h)
{
    if(h<0)
    return -h;
    return h;
}
int check(long long x, long long y)
{
    dif=x-y;
    countt=0;
    ucit=y;
    for(int i=3;i<=n;i++)
    {
        ucit-=dif;
        if(ab(ucit-a[i])==1)
            countt++;
        else if(ab(ucit-a[i])>1)
            return 0;
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    if(n<=2)
    {
        puts("0");
        return 0;
    }
    for(int i=-1;i<=1;i++)
    for(int j=-1;j<=1;j++)
    if(check(a[1]+i, a[2]+j))
    {
        if(i!=0)
            countt++;
        if(j!=0)
            countt++;
        if(ans>countt)
            ans=countt;
    }
    if(ans==123456789)
    puts("-1");
    else
    printf("%d",ans);
}

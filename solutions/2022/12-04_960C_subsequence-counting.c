/* Codeforces 960C - Subsequence Counting
 * https://codeforces.com/problemset/problem/960/C
 * rating: 1700 | tags: bitmasks, constructive algorithms, greedy, implementation
 * source: accepted submission #37075129 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
long long i,x,d,p=1;
long long ans[5000000],c;
int check()
{
    if(c>10000)
    return 1;
    for(int j=0;j<c;j++)
    if(ans[j]>1000000000000000000LL)
    return 1;
    return 0;
}
int main()
{
    scanf("%I64d%I64d",&x,&d);
    while(x>0)
    {
        for(i=62;i>=0;i--)
        if((1LL<<i)<=(x+1))
        break;
        for(int j=1;j<=i;j++)
        ans[c++]=p;
        p+=d;
        x-=(1LL<<i)-1;
    }
    if(check())
    puts("-1");
    else
    {
        printf("%d\n",c);
        for(int j=0;j<c;j++)
        printf("%I64d ",ans[j]);
    }
}

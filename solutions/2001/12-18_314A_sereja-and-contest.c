/* Codeforces 314A - Sereja and Contest
 * https://codeforces.com/problemset/problem/314/A
 * rating: 1600 | tags: implementation
 * source: accepted submission #3837850 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
    long long n,k,i,prevsum=0,removed=0,a,d;
    scanf("%I64d%I64d",&n,&k);
    for(i=1;i<=n;++i)
    {
        scanf("%I64d",&a);
        d=prevsum-(i-removed-1)*(n-i)*a;
        if(d<k)
        {
            printf("%I64d\n",i);
            ++removed;
        }
        else
        {
            prevsum+=a*(i-removed-1);
        }
    }
    return 0;
}

/* Codeforces 1379B - Dubious Cyrpto
 * https://codeforces.com/problemset/problem/1379/B
 * rating: 1500 | tags: binary search, brute force, math, number theory
 * source: accepted submission #87308854 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
typedef long long int ll;
int main()
{
    ll t,l,r,m,x,y;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&l,&r,&m);
        for(ll i=l;i<=r;i++)
        {
            x=m%i;
            y=m/i;
            if((x<=(r-l))&(y!=0))
            {
                printf("%lld %lld %lld\n",i,r,r-x);
                break;
            }
            else if((i-x)<=(r-l))
            {
                printf("%lld %lld %lld\n",i,l,l+(i-x));
                break;
            }
        }
    }
}

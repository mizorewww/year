/* Codeforces 1342C - Yet Another Counting Problem
 * https://codeforces.com/problemset/problem/1342/C
 * rating: 1600 | tags: math, number theory
 * source: accepted submission #78204612 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
long long int re[110][510];
int q[110];

long long int gcd(long long int a,long long int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int T,t;
    int i;
    long long int a,b,l,r,lcm;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        scanf("%lld %lld",&a,&b);
        if(a>b)
        {
            lcm=a;
            a=b;
            b=lcm;
        }
        scanf("%d",&q[t]);
        lcm=a/gcd(b,a)*b;
        for(i=0;i<q[t];i++)
        {
            scanf("%lld %lld",&l,&r);
            l--;
            re[t][i]+=r/lcm*(lcm-b)+(r%lcm>b-1?r%lcm-b+1:0);
            re[t][i]-=l/lcm*(lcm-b)+(l%lcm>b-1?l%lcm-b+1:0);
        }
    }
    for(t=0;t<T;t++)
    {
        for(i=0;i<q[t];i++) printf("%lld ",re[t][i]);
        printf("\n");
    }
    return 0;
}

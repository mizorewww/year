/* Codeforces 1006B - Polycarp's Practice
 * https://codeforces.com/problemset/problem/1006/B
 * rating: 1200 | tags: greedy, implementation, sortings
 * source: accepted submission #40425710 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long x[10000], t[10000];

int main()
{
    long long n, k, i, p, a, w;

    scanf("%I64d%I64d", &n, &k);

    for(i=0; i<n; i++)
    {
        scanf("%I64d", &x[i]);
        t[x[i]]++;
    }
    a=k;
    w=0;

    for(i=3000; i>=0; i--)
    {
        k-=t[i];
        if(k<0){t[i]+=k;k=0;}
        w+=t[i]*i;
    }
    printf("%I64d\n", w);
    p=-1;
    for(i=0; a>1; i++)
    {
        if(t[x[i]]>0){t[x[i]]--; a--; printf("%I64d ", i-p); p=i;}
    }
    printf("%I64d", n-p-1);


    return 0;
}

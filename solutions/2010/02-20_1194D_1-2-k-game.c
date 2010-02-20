/* Codeforces 1194D - 1-2-K Game
 * https://codeforces.com/problemset/problem/1194/D
 * rating: 1700 | tags: games, math
 * source: accepted submission #57049370 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, p, m, k, t, i, j, k, q, ls, la, lb, x[50001], y, g, w, e, c, d, a, b;
char s[200];


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
    scanf("%d", &t);

    for(q=0; q<t; q++)
    {
        scanf("%d%d", &a, &b);
        if(b%3==0)a=a%(b+1);
        if(a%3!=0 || a==b)printf("Alice\n");
        else printf("Bob\n");
    }

    return 0;
}

/* Codeforces 1131C - Birthday
 * https://codeforces.com/problemset/problem/1131/C
 * rating: 1200 | tags: binary search, greedy, sortings
 * source: accepted submission #50365163 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int i, j, n, m, x, b, k, w[1000], p, a, y, t[200], q;
int war(const void*c, const void*d)
{
    return(*(int*)d-*(int*)c);
}

char s[400000];

int main()
{
    scanf("%d", &q);

    for(i=0; i<q; i++)
    {
        scanf("%d", &t[i]);
    }

    qsort(t,q,4,war);

    for(i=0; i<q; i++)
    {
        if(i%2==0)w[i/2]=t[i];
        else w[q-1-i/2]=t[i];
    }

    for(i=0; i<q; i++)
    {
        printf("%d ", w[i]);
    }

    return(0);
}

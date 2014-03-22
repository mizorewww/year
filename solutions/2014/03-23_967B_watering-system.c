/* Codeforces 967B - Watering System
 * https://codeforces.com/problemset/problem/967/B
 * rating: 1000 | tags: math, sortings
 * source: accepted submission #37712788 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

int s[500000];

int war(const void* a, const void* b)
{
    return(*(int*)b-*(int*)a);
}

int main()
{
    int n, a, b, w, i, x;

    scanf("%d%d%d%d", &n, &a, &b, &x);

    w=x;
    n--;

    for(i=0; i<n; i++)
    {
        scanf("%d", &s[i]);
        w+=s[i];
    }

    qsort(s, n, 4, war);

    i=-1;

    while((x*a)/w<b)
    {
        i++;
        w-=s[i];
    }


    printf("%d\n", i+1);

    return 0;
}

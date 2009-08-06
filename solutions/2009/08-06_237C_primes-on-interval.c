/* Codeforces 237C - Primes on Interval
 * https://codeforces.com/problemset/problem/237/C
 * rating: 1600 | tags: binary search, number theory, two pointers
 * source: accepted submission #2431442 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

#define MAXN 1000020

int iscomp[MAXN];

int main()
{    
    int i, j;
    iscomp[0] = iscomp[1] = 1;
    for (i = 2; i < MAXN; ++i) 
        if (!iscomp[i])
            for (j = i + i; j < MAXN; j += i) 
                iscomp[j] = 1;
    
    int primesto[MAXN];
    primesto[0] = primesto[1] = 0;
    for (i = 2; i < MAXN; ++i)
        if (!iscomp[i])
            primesto[i] = 1 + primesto[i - 1];
        else primesto[i] = primesto[i - 1];

    int a, b, k;
    int l, p, x;
    scanf("%d %d %d", &a, &b, &k);
    if (primesto[b] - primesto[a - 1] < k) {
        printf("-1\n");
        return 0;
    }
    int lo = k - 1, hi = b - a + 2;
    int poz = -1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int flag = 1;
        for (p = a; p <= b - mid + 1 && flag; ++p) 
            if (primesto[p + mid - 1] - primesto[p - 1] < k) {
                flag = 0;
                lo = mid + 1;
            }
        if (flag) {
            poz = mid;
            hi = mid;
        }
    }
    printf("%d\n", poz);

    return 0;
}

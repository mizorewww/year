/* Codeforces 962C - Make a Square
 * https://codeforces.com/problemset/problem/962/C
 * rating: 1400 | tags: brute force, implementation, math
 * source: accepted submission #37157299 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    long long n, i, s, nc, nop, min_nop;

    scanf("%lld", &n);
    min_nop = LLONG_MAX;

    for (i = 1; i * i <= n; i++) {
        s = i * i;
        nc = n;
        nop = 0;

        while (nc && s) {
            if (nc % 10 == s % 10) {
                s /= 10;
            } else {
                nop++;
            }

            nc /= 10;
        }

        if (s == 0) {
            while (nc) {
                nop++;
                nc /= 10;
            }

            if (nop < min_nop) {
                min_nop = nop;
            }
        }
    }

    printf("%lld\n", min_nop == LLONG_MAX ? -1 : min_nop);

    return 0;
}

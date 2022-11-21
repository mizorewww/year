/* Codeforces 960B - Minimize the error
 * https://codeforces.com/problemset/problem/960/B
 * rating: 1500 | tags: data structures, greedy, sortings
 * source: accepted submission #37075009 (GNU C11) downloaded from Codeforces
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    long long n, k1, k2, max = 0, maxi = -1;
    long long err = 0;
    long long m1[10010], m2[10010];
    scanf("%I64d%I64d%I64d", &n, &k1, &k2);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &m1[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &m2[i]);
    }
    for (int j = 0; j < k1 + k2; j++) {
        max = 0;
        maxi = -1;
        for (int i = 0; i < n; i++) {
            if (llabs(m1[i] - m2[i]) > max) {
                max = llabs(m1[i] - m2[i]);
                maxi = i;
            }
        }
        if (maxi == -1) {
            printf("%I64d", (k1 + k2 - j) % 2);
            return 0;
        }
        if (m1[maxi] > m2[maxi]) m1[maxi]--;
        else m1[maxi]++;
    }
    for (int i = 0; i < n; i++) err += (m1[i] - m2[i]) * (m1[i] - m2[i]);
    printf("%I64d", err);
    return 0;
}

/* Codeforces 1497C2 - k-LCM (hard version)
 * https://codeforces.com/problemset/problem/1497/C2
 * rating: 1600 | tags: constructive algorithms, math
 * source: accepted submission #110232021 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

void solve() {
    long long q;
    int k;

    scanf("%lld %d", &q, &k);

    long long n = q - k + 3;

    if (n % 3 == 0) {
        printf("%lld %lld %lld ", n / 3, n / 3, n / 3);
    } else {
        if (n % 2 == 1) {
            printf("%lld %lld %d ", n / 2, n / 2, 1);
        } else {
            int m = n / 2;
            if (m % 2 == 1) {
                printf("%d %d %d ", m - 1, m - 1, 2);
            } else {
                printf("%d %d %d ", m, m / 2, m / 2);
            }
        }
    }

    for (int i = 0; i < (k - 3); i++)
        printf("%d ", 1);
}

int main (int argc, char *argv[]) {

    int t; scanf("%d", &t);

    while(t--) { solve(); puts(""); }

return 0;
}

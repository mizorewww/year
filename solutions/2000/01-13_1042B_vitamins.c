/* Codeforces 1042B - Vitamins
 * https://codeforces.com/problemset/problem/1042/B
 * rating: 1200 | tags: bitmasks, brute force, dp, implementation
 * source: accepted submission #42977673 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#define min(a, b) ((a)>(b)?(b):(a))
// 최대 3개의 비타민을 포함할 수 있다.
int d[100];
int a[1000];
int c[1000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 100; i++) {
        d[i] = 987654321;
    }
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        char s[4];
        scanf("%d %s", &a[i], s);
        int len = strlen(s);
        for (int j = 0; j < len; j++) {
            if (s[j] == 'A') {
                c[i] |= 1;
            } else if (s[j] == 'B') {
                c[i] |= 2;
            } else {
                c[i] |= 4;
            }
        }
    }
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j < n; j++) {
            d[i|c[j]] = min(d[i|c[j]], d[i] + a[j]);
        }
    }
    if (d[7] == 987654321) {
        printf("-1\n");
    } else {
        printf("%d\n", d[7]);
    }
    return 0;
}

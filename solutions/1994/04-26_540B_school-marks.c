/* Codeforces 540B - School Marks
 * https://codeforces.com/problemset/problem/540/B
 * rating: 1700 | tags: greedy, implementation
 * source: accepted submission #10950851 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main() {
    int n, k, p, x, y, i;
    int a, sum = 0, l = 0, r = 0;
    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
    for (i = 0; i < k; i++) {
        scanf("%d", &a);
        sum += a;
        if (a < y) l++;
        else r++;
    }
    l = (n - 1) / 2 - l;
    r = (n + 1) / 2 - r;
    if (l < 0) {
        printf("-1");
        return 0;
    }
    if (r < 0) {
        l += r;
        r ^= r;
    }
    sum += l + r * y;
    if (sum > x) {
        printf("-1");
        return 0;
    }
    p = 0;
    while (l--) {
        if (p) printf(" ");
        printf("1");
        p = 1;
    }
    while (r--) {
        if (p) printf(" ");
        printf("%d", y);
        p = 1;
    }
    return 0;
}

/* Codeforces 770A - New Password
 * https://codeforces.com/problemset/problem/770/A
 * rating: 800 | tags: *special, implementation
 * source: accepted submission #25408262 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        putchar('a' + (i % k));
    }
    putchar('\n');

    return 0;
}

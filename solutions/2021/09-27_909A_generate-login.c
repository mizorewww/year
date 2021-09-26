/* Codeforces 909A - Generate Login
 * https://codeforces.com/problemset/problem/909/A
 * rating: 1000 | tags: brute force, greedy, sortings
 * source: accepted submission #33680049 (GNU C) downloaded from Codeforces
 */

#include "stdio.h"
int main() {
    char a[10], b[10];
    scanf("%s%s", a, b);
    putchar(a[0]);
    for(char i = 1; a[i] < b[0] && a[i]; i++) putchar(a[i]);
    putchar(b[0]);
    return 0;
}

/* Codeforces 888B - Buggy Robot
 * https://codeforces.com/problemset/problem/888/B
 * rating: 1000 | tags: greedy
 * source: accepted submission #32163762 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int com[150];
char s[1005];

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, i, tot;
    scanf("%d%s", &n, s);
    for(i = 0; i < n; ++i)
        ++com[s[i]];
    tot = 2 * (min(com['U'], com['D']) + min(com['L'], com['R']));
    printf("%d\n", tot);
    return 0;
}

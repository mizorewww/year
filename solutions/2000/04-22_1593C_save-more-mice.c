/* Codeforces 1593C - Save More Mice
 * https://codeforces.com/problemset/problem/1593/C
 * rating: 1000 | tags: binary search, greedy
 * source: accepted submission #131784295 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

int xi[500005];

void smallsort(int a[], int len) {
    for (int h = 1743392200; h; h /= 3)
        for (int i = h; i < len; i++) {
            register int tmp = a[i], *j = a + i - h;
            while (j >= a && j[0] > tmp)
                j[h] = j[0], j -= h;
            j[h] = tmp;
        }
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= k; i++)
            scanf("%d", &xi[i]);
        smallsort(xi + 1, k);
        long long fucker = 0, ans = 0;
        for (int i = k; i; i--)
        {
            if (fucker < xi[i])
            {
                ans++;
                fucker += n - xi[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

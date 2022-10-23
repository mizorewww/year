/* Codeforces 1542C - Strange Function
 * https://codeforces.com/problemset/problem/1542/C
 * rating: 1600 | tags: math, number theory
 * source: accepted submission #121225499 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int num[2333], cnt[2333];
int tot = 0;
long long p = 1e9 + 7;
int main()
{
    for (int i = 2; i <= 8000; ++i)
    {
        int tmp = i;
        for (int j = 1; j <= tot; ++j)
            if (tmp % num[j] == 0)
                tmp /= num[j];
        if (tmp == 1)
            ++cnt[tot];
        else 
            num[++tot] = tmp,
            cnt[tot] = 1;
    }
    // printf("%d", tot);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long x, ans = 0, now = num[1], i = 1;
        scanf("%lld", &x);
        while (i <= tot && now <= x)
        {
            ans = (ans + (x / now) * cnt[i]) % p;
            ++i;
            now *= num[i];
        }
        ans = (ans + x * 2) % p;
        printf("%lld\n", ans);
    }
    return 0;
}

/* Codeforces 855E - Salazar Slytherin's Locket
 * https://codeforces.com/problemset/problem/855/E
 * rating: 2200 | tags: bitmasks, dp
 * source: accepted submission #30677961 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

long long dp[12][64][1025];
int len = 0, ar[64], temp[64];

int convert(int b, long long v){
    int i, j, k = 0;
    while (v){
        temp[k++] = v % b;
        v /= b;
    }

    for (len = 0, i = k - 1; i >= 0; i--) ar[len++] = temp[i];
    return len;
}

long long F(int b, int n, int mask, int cur){
    if (n == 0) return (cur == 0);
    if (dp[b][n][cur] != -1) return dp[b][n][cur];

    int i;
    long long res = 0;
    for (i = 0; i < b; i++){
        res += F(b, n - 1, mask | (1 << i), cur ^ (1 << i));
    }

    return (dp[b][n][cur] = res);
}

long long dfs(int b, int i, int mask, int cur, int nz){
    if (i == len) return F(b, 0, mask, cur);

    long long res = 0;
    int j, x, lim = ar[i];
    for (j = 0; j < lim; j++){
        if (i == 0 && j == 0) continue;
        res += F(b, len - i - 1, mask | (1 << j), cur ^ (1 << j));
    }

    res += dfs(b, i + 1, mask | (1 << j), cur ^ (1 << j), 1);
    return res;
}

long long solve(int b, long long v){
    if (v == 0) return 0;

    int i, j;
    len = convert(b, v);
    long long res = dfs(b, 0, 0, 0, 0);

    for (i = 1; i < len; i++){
        for (j = 1; j < b; j++){
            res += F(b, i - 1, 1 << j, 1 << j);
        }
    }

    return res;
}


int main(){
    int q, b, i;
    long long l, r, res;
    memset(dp, -1, sizeof(dp));

    scanf("%d", &q);
    while (q--){
        scanf("%d %lld %lld", &b, &l, &r);
        res = solve(b, r) - solve(b, l - 1);
        printf("%lld\n", res);
    }
    return 0;
}

/* Codeforces 815B - Karen and Test
 * https://codeforces.com/problemset/problem/815/B
 * rating: 2200 | tags: brute force, combinatorics, constructive algorithms, math
 * source: accepted submission #27860421 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 1000010
#define MOD 1000000007
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)

long long ar[MAX], fact[MAX];

long long expo(long long x, long long n){
    long long res = 1;

    while (n){
        if (n & 1LL) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1LL;
    }

    return (res % MOD);
}

long long binomial(int n, int k){
    long long x = fact[n];
    long long y = (fact[k] * fact[n - k]) % MOD;
    long long res = (x * expo(y, MOD - 2)) % MOD;
    return res;
}

long long solve(int n, long long ar[MAX]){
    if (n == 1) return ar[0] % MOD;

    int i, j, k;
    long long x, y, z, res = 0;

    if ((n % 4) == 0){
        for (i = 0; i < n; i++){
            x = binomial(n / 2 - 1, i / 2) * ar[i] % MOD;
            if (i % 2 == 1) res = (res - x + MOD) % MOD;
            else res = (res + x) % MOD;
        }
    }

    if ((n % 4) == 1){
        for (i = 0; i < n; i++){
            if (i % 2 == 0) res = (res + binomial(n / 2, i / 2) * ar[i]) % MOD;
        }
    }

    if ((n % 4) == 2){
        for (i = 0; i < n; i++){
            res = (res + binomial(n / 2 - 1, i / 2) * ar[i]) % MOD;
        }
    }

    if ((n % 4) == 3){
        for (i = 0; i < n; i++){
            if ((i % 2) == 1){
                x = binomial(n / 2 - 1, i / 2) * 2 % MOD;
            }
            else{
                x = binomial(n / 2 - 1, i / 2);
                if (i) x = (x - binomial(n / 2 - 1, i / 2 - 1) + MOD) % MOD;
                if ((2 * i) > n) x = x - MOD;
            }

            res = (res + ((x * ar[i]) % MOD) + MOD) % MOD;
        }
    }
    return res % MOD;
}

int main(){
    int n, i, j, k;
    for (i = 1, fact[0] = 1; i < MAX; i++) fact[i] = (fact[i - 1] * i) % MOD;

    while (scanf("%d", &n) != EOF){
        for (i = 0; i < n; i++) scanf("%lld", &ar[i]);
        printf("%lld\n", solve(n, ar));
    }
    return 0;
}

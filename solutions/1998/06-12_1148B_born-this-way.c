/* Codeforces 1148B - Born This Way
 * https://codeforces.com/problemset/problem/1148/B
 * rating: 1600 | tags: binary search, brute force, two pointers
 * source: accepted submission #54932643 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

long long a[200002], b[200002];

int bs(int n, int v)
{
    int l = 0, r = n - 1, m;
    while(l < r){
        m = (l + r) / 2;
        if(b[m] < v) l = m + 1;
        else r = m;
    }
    return l;
}

int main()
{
    int n, m, k, i;
    long long ta, tb, ans = 0;
    scanf("%d%d%I64d%I64d%d", &n, &m, &ta, &tb, &k);
    for(i = 0; i < n; i++) scanf("%I64d", &a[i]);
    for(i = 0; i < m; i++) scanf("%I64d", &b[i]);
    if(k >= n || k >= m || a[k] + ta > b[m - 1]){
        printf("-1");
        return 0;
    }
    for(i = 0; i <= k; i++){
        int t = bs(m, a[i] + ta);
        if(t + k - i >= m){
            printf("-1");
            return 0;
        }
        if(ans < b[t + k - i] + tb) ans = b[t + k - i] + tb;
    }
    printf("%I64d", ans);
}

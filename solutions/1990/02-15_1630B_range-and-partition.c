/* Codeforces 1630B - Range and Partition
 * https://codeforces.com/problemset/problem/1630/B
 * rating: 1800 | tags: binary search, constructive algorithms, data structures, greedy, two pointers
 * source: accepted submission #144239554 (GNU C11) downloaded from Codeforces
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CL while (getchar() != '\n') /*clear line*/
#define FOR(a, b, c)                          \
    for (int(a) = (b);                        \
         (b) < (c) ? (a) <= (c) : (a) >= (c); \
         (b) < (c) ? (a)++ : (a)--)
#define FN(x) /*input x and run x times*/ \
    int x;                                \
    scanf("%d", &x);                      \
    while (x--)
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a < b ? b : a)
#define LL long long
#define eps 0.000001
#define pf printf
#define sf scanf
#define vp const void*
int cmp(vp a, vp b) {
    int k1 = *(int*)(a), k2 = *(int*)(b);
    return (k1 > k2) * 2 - 1;
}
int a[210000],pre[210000];
int main() {
    FN(q) {
        int n, k, t;
        sf("%d%d", &n, &k);
        t = (n+k+1) / 2;
        FOR(i, 1, n)
        sf("%d", a + i), pre[a[i]]++;
        FOR(i, 1, n)
        pre[i] += pre[i - 1];

        int m = n + 1,d=1;
        {
            int i = 0, j = 1;
            while (i <= n-1) {
                while (pre[j] - pre[i] < t) {
                    j++;
                    if (j > n)break;
                }
                if(j>n)break;
                if(d)m = min(m, j - i);
                i++;
            }
        }
        
        int i = 0, j = 1;
        while (i <= n-1) {
            while (pre[j] - pre[i] < t)
                j++;
            if (m == j - i)
                break;
            i++;
        }
        printf("%d %d\n", i + 1, j);
        int inn = 0, out = 0, time = 0,p=1;
        FOR(l, 1, n) {
            if (a[l] > i && a[l] <= j)
                inn++;
            else
                out++;
            if(inn>out&&time<k-1){
                inn=0,out=0;
                printf("%d %d\n",p,l);
                p=l+1;
                time++;
            }
        }
        printf("%d %d\n",p,n);

        FOR(i, 1, n)
        pre[i] = a[i] = 0;
    }
    return 0;
}

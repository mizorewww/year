/* Codeforces 1159B - Expansion coefficient of the array
 * https://codeforces.com/problemset/problem/1159/B
 * rating: 1300 | tags: implementation, math
 * source: accepted submission #54031082 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n;
    scanf("%d", &n);

    int ans = 1000000000;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d",&a);
        
        ans = min(ans, a / max(i, n - i - 1));
    }

    printf("%d\n", ans);
    return 0;
}

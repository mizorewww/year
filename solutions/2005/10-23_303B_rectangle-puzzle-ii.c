/* Codeforces 303B - Rectangle Puzzle II
 * https://codeforces.com/problemset/problem/303/B
 * rating: 1700 | tags: implementation, math
 * source: accepted submission #3709819 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int gcd(int a, int b){
    while ((a %= b) && (b %= a));
    return a + b;
}

int main(){
    int n, m, x, y, a, b, g, r, x1, y1;
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
    g = gcd(a, b);
    a /= g, b /= g;
    r = n / a;
    if (m / b < r)r = m / b;
    a *= r, b *= r;
    if (x + a / 2 >= n)x1 = n - a;
    else if (x - a / 2 <= 0)x1 = 0;
    else x1 = x - (a + 1) / 2;
    if (y + b / 2 >= m)y1 = m - b;
    else if (y - b / 2 <= 0)y1 = 0;
    else y1 = y - (b + 1) / 2;
    printf("%d %d %d %d\n", x1, y1, x1 + a, y1 + b);
    return 0;
}

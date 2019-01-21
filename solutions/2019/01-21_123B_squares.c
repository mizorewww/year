/* Codeforces 123B - Squares
 * https://codeforces.com/problemset/problem/123/B
 * rating: 1800 | tags: math
 * source: accepted submission #832013 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define abs(a) ((a) < 0) ? (-(a)) : (a)

int
main(void)
{
    int a, b, x1, y1, x2, y2;
    scanf("%d%d%d%d%d%d", &a, &b, &x1, &y1, &x2, &y2);
    int
        x_1 = (x1 + y1 > 0) ? (x1 + y1) / (2 * a) : (x1 + y1) / (2 * a) - 1,
        y_1 = (x1 - y1 > 0) ? (x1 - y1) / (2 * b) : (x1 - y1) / (2 * b) - 1,
        x_2 = (x2 + y2 > 0) ? (x2 + y2) / (2 * a) : (x2 + y2) / (2 * a) - 1,
        y_2 = (x2 - y2 > 0) ? (x2 - y2) / (2 * b) : (x2 - y2) / (2 * b) - 1;
    printf("%d", max(abs(x_1 - x_2), abs(y_1 - y_2)));
    return 0;
}

/* Codeforces 1562D1 - Two Hundred Twenty One (easy version)
 * https://codeforces.com/problemset/problem/1562/D1
 * rating: 1700 | tags: data structures, dp, math
 * source: accepted submission #127108739 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int main() {
  int t, n, q, l, r;
  int pre[300001];
  int d;
  *pre = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d\n", &n, &q);
    for (int i = 0; i < n; i++) {
      d = getc(stdin);
      pre[i + 1] = pre[i] + ((d == '+') ^ (i & 1)) * 2 - 1;
    }
    while (q--) {
      scanf("%d %d", &l, &r);
      d = pre[r] - pre[l - 1];
      if (d == 0)
        puts("0");
      else if (d & 1)
        puts("1");
      else
        puts("2");
    }
  }
  return 0;
}

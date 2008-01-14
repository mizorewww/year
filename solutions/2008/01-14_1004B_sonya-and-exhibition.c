/* Codeforces 1004B - Sonya and Exhibition
 * https://codeforces.com/problemset/problem/1004/B
 * rating: 1300 | tags: constructive algorithms, greedy, implementation, math
 * source: accepted submission #39997603 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; ++i) {
    putchar('0' + i % 2);
  }
  putchar('\n');
  return 0;
}

/* Codeforces 1657C - Bracket Sequence Deletion
 * https://codeforces.com/problemset/problem/1657/C
 * rating: 1200 | tags: greedy, implementation
 * source: accepted submission #150491810 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main () {
  int t = 0;
  int n = 0;
  char s[500001] = "";
  
  int res = 0;
  
  res = scanf("%d", &t);
  
  while (t > 0) {
    int cnt = 0;
    int idx = 0;
    int is_fin = 0;
    res = scanf("%d", &n);
    res = scanf("%s", s);
    while (is_fin <= 0) {
      if (idx > n-2) {
        is_fin = 1;
      } else if (s[idx] != ')' || s[idx+1] != '(') {
        idx += 2;
        cnt++;
      } else {
        int tmp = idx;
        idx += 2;
        while (idx < n && s[idx] != ')') {
          idx++;
        }
        if (idx < n) {
          cnt++;
          idx++;
        } else {
          idx = tmp;
          is_fin = 1;
        }
      }
    }
    printf("%d %d\n", cnt, n-idx);
    t--;
  }
  
  return 0;
}

/* Codeforces 1647C - Madoka and Childish Pranks
 * https://codeforces.com/problemset/problem/1647/C
 * rating: 1300 | tags: constructive algorithms, greedy
 * source: accepted submission #149290026 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main () {
  int t = 0;
  int n = 0;
  int m = 0;
  char s[100][101] = {};
  
  int res = 0;
  
  int ans[10000][4] = {};
  
  res = scanf("%d", &t);
  
  while (t > 0) {
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
      res = scanf("%s", s[i]);
    }
    if (s[0][0] == '1') {
      printf("-1\n");
    } else {
      int ans_num = 0;
      for (int sum = n+m-2; sum > 0; sum--) {
        for (int i = 0; i < n; i++) {
          int j = sum-i;
          if (j >= 0 && j < m && s[i][j] == '1') {
            if (i > 0) {
              ans[ans_num][0] = i;
              ans[ans_num][1] = j+1;
            } else {
              ans[ans_num][0] = i+1;
              ans[ans_num][1] = j;
            }
            ans[ans_num][2] = i+1;
            ans[ans_num][3] = j+1;
            ans_num++;
          }
        }
      }
      printf("%d\n", ans_num);
      for (int i = 0; i < ans_num; i++) {
        printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
      }
    }
    t--;
  }
  
  return 0;
}

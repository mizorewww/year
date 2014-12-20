/* Codeforces 1380B - Universal Solution
 * https://codeforces.com/problemset/problem/1380/B
 * rating: 1400 | tags: greedy
 * source: accepted submission #86674737 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

#define MAXN 1000007
#define max(a, b) ((a) > (b)? (a): (b))

char s[MAXN];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int wr = 0, ws = 0, wp = 0;
    for (int i = 0; i < n; i ++) {
      if (s[i] == 'R') wp ++;
      else if (s[i] == 'S') wr ++;
      else ws ++;
    }
    int wmax = max(max(wr, ws), wp);
    char c;
    if (wr == wmax) c = 'R';
    else if (ws == wmax) c = 'S';
    else c = 'P';
    for (int i = 0; i < n; i ++) putchar(c);
    putchar('\n');
  }

  return 0;
}

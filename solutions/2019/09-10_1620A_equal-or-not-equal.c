/* Codeforces 1620A - Equal or Not Equal
 * https://codeforces.com/problemset/problem/1620/A
 * rating: 800 | tags: constructive algorithms, dsu, implementation
 * source: accepted submission #139761448 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    char s[100];
    scanf("%s", s);
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++)
      if (s[i] == 'N') n++;
    puts(n == 1 ? "NO" : "YES");
  }

  return 0;
}

/* Codeforces 1236E - Alice and the Unfair Game
 * https://codeforces.com/problemset/problem/1236/E
 * rating: 2500 | tags: binary search, data structures, dp, dsu
 * source: accepted submission #62808684 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
int N = 200000;

int n, m;
int a[200000];
int f[400000];
int fr[400000];
long long ans;
int shift = 200000;

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}


int min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }

  for (int i = m; i >= 1; i--) {
    f[a[i] + shift] = max(f[a[i] + shift], f[a[i] + shift - 1] + 1);
  }

  for (int i = 1; i <= n; i++) {
    ans += min(n - i + 1, m - f[i + shift] + 2);
  }

  for (int i = 1; i <= m; i++) {
    a[i] += i;
    a[i] = n - a[i] + 1;
    a[i] -= i;
  }

  for (int i = m; i >= 1; i--) {
    fr[a[i] + shift] = max(fr[a[i] + shift], fr[a[i] + shift - 1] + 1);
  }

  for (int i = 1; i <= n; i++) {
    ans += min(n - i + 1, m - fr[i + shift] + 2);
    ans--;
  }

  printf("%I64d", ans);


  return 0;
}

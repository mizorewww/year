/* Codeforces 1380D - Berserk And Fireball
 * https://codeforces.com/problemset/problem/1380/D
 * rating: 2000 | tags: constructive algorithms, greedy, implementation, math, two pointers
 * source: accepted submission #86689837 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define MAXN 200007
#define max(a, b) ((a) > (b) ? (a): (b))
#define min(a, b) ((a) < (b) ? (a): (b))

int n, m, x, y, k;
int a[MAXN], b[MAXN];

int q[MAXN], ql;

long long solve() {
  int i, j = 0;
  long long ans = 0;
  for (i = 0; i < m; i ++) {
    ql = 0;
    int maxa = 0, maxe = max(b[i], i-1 >= 0 ? b[i-1]: 0);
    while (j < n && a[j] != b[i]) {
      q[ql++] = a[j];
      maxa = max(a[j], maxa);
      j ++;
    }
    if (a[j] != b[i]) return -1;
    if (ql) {
      if (ql < k && maxa > maxe) return -1;

      if (ql < k) ans += (long long)y*ql;
      else {
        long long r = ql % k;
        long long ans1 = (long long)x * (ql/k) + (long long)r*y;
        long long ans2 = maxa < maxe ? (long long)ql*y: (long long)x + (long long)(ql-k)*y;
        ans += min(ans1, ans2);
      }
    }

    j ++;
  }
  return ans;
}

int main() {
  scanf("%d%d%d%d%d", &n, &m, &x, &k, &y);
  for (int i = 0; i < n; i ++) scanf("%d", a+i);
  for (int i = 0; i < m; i ++) scanf("%d", b+i);

  a[n++] = b[m++] = 0;

  printf("%lld", solve());

  return 0;
}

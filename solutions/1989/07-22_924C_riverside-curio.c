/* Codeforces 924C - Riverside Curio
 * https://codeforces.com/problemset/problem/924/C
 * rating: 1700 | tags: data structures, dp, greedy
 * source: accepted submission #36899092 (GNU C) downloaded from Codeforces
 */

//greedy
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define N 100000
int a[N];
int len[N];

int main() {
 int n;
 while(scanf("%d", &n)==1) {
  int cur=0; 
  long long ans=0;
  memset(a, 0, sizeof(int)*n);
  for(int d=0; d<n; d++) {
   int u;
   scanf("%d", &u);
   len[d] = 1;
   if (u<cur) {
    ans += cur-u-1;
    if (d && a[d]==a[d-1]) len[d] += len[d-1];
   }
   else {
    a[d] = 1;
    long long x = u-cur;
    int last = d;
    for(int e=d-1; e>=0 && x; ) {
     int k=len[e];

     if (a[e]==1) {
      ans += x*k;
     }
     else {
      if (k>x) {
       k = x;
       len[e] = k;
      }
      else {
       int pre = e-k;
       while (pre && a[pre]==1) {
        len[e] += len[pre];
        pre -= len[pre];
       }
      }
      //x + x-1 + x-2 + ... + x-k+1 [k items]
      ans += (x+x-k+1)*k/2;
      x -= k;
      a[e] = 1;
     }
     len[last] += k;
     e -= k;
    }
    cur = u+1;
    /*
    for(int e=d-1; e>=0 && x; e--) {
     ans += x;
     if (a[e]==0) {
      a[e]=1;
      x--;
     }
    }
    */
   }
  }
  printf("%lld\n", ans);
 }
}

/* Codeforces 590A - Median Smoothing
 * https://codeforces.com/problemset/problem/590/A
 * rating: 1700 | tags: implementation
 * source: accepted submission #13847007 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#define N 500100

int s[N];

int main() {
 int n, i, j, k, b, e, x, m = 0;

 scanf("%d", &n);
 for(i=0; i<n; i++) {
  scanf("%d", &s[i]);
 }

 for(i=1; i<n; i++) {
  if(s[i] != s[i-1]) {
   b = i-1;
   x = !s[i];
   j = i+1;
   while(s[j] == x && j < n) {
    x = !x;
    j++;
   }
   e = j-1;

   if(s[b] == s[e]) {
    for(j=b+1; j<e; j++) s[j] = s[b];
   } else {
    j=b; k=e;
    while(j<k) {
     s[j] = s[b];
     s[k] = s[e];
     j++; k--;
    }
   }

   if((e-b)/2 > m) m = (e-b)/2;

   i = e+1;
  }
 }

 printf("%d\n", m);
 for(i=0; i<n; i++) {
  printf("%d ", s[i]);
 }
 printf("\n");

}

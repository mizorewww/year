/* Codeforces 1398A - Bad Triangle
 * https://codeforces.com/problemset/problem/1398/A
 * rating: 800 | tags: geometry, math
 * source: accepted submission #89908599 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main(){
  int n,t,i,j,a[50001];
  scanf("%d",&t);
  for (i=0;i<t;i++){
    scanf("%d",&n);
    for (j=0;j<n;j++){
      scanf("%d",&a[j]);
    }
    if (a[0]+a[1]<=a[n-1]) printf("1 2 %d\n",n);
    else printf("-1\n");
  }
}

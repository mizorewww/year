/* Codeforces 24C - Sequence of points
 * https://codeforces.com/problemset/problem/24/C
 * rating: 1800 | tags: geometry, implementation, math
 * source: accepted submission #102773 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
typedef long long ll;
#define M 131072
int a[M],b[M];
int n;
int x,y;
ll mx,my;
ll times;
ll dx,dy;
char s[1024];

int main() {
  int i,j,k;
  scanf("%d %s",&n,&s);
  for(i=times=0;s[i];i++) times=times*10+s[i]-48;
  scanf("%d %d",&x,&y);
  mx=x,my=y;
  for(i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
  if(times%(2*n)) for(j=k=0;;) {
    mx=a[j]+a[j]-mx;
    my=b[j]+b[j]-my;
    j++; if(j==n) j=0;
    k++;
    if(times%(2*n)==k) break;
  }
  printf("%I64d %I64d\n",mx,my);
  return 0;
}

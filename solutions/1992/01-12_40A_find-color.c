/* Codeforces 40A - Find Color
 * https://codeforces.com/problemset/problem/40/A
 * rating: 1300 | tags: constructive algorithms, geometry, implementation, math
 * source: accepted submission #177849 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <math.h>

int main() {
  int x,y,e;
  double d;
  scanf("%d %d",&x,&y);
  if(!x || !y) { puts("black"); return 0; }
  d=sqrt(x*x+y*y);
  e=d+1e-8;
  if(d-e<1e-8) { puts("black"); return 0; }
  if(x<0) e^=1;
  if(y<0) e^=1;
  if(e&1) puts("white");
  else puts("black");
  return 0;
}

/* Codeforces 1225C - p-binary
 * https://codeforces.com/problemset/problem/1225/C
 * rating: 1600 | tags: bitmasks, brute force, math
 * source: accepted submission #63471880 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int bitc(int x){
  int toret;
  for(toret = 0;x;x&=(x - 1))toret++;
  return toret;
}

int main(){
  int n, p;
  scanf("%d %d", &n, &p);
  int i, ans;
  ans = -1;
  for(i = 1;i < 900;i++){
    int rem = n - i*p;
    if(rem >= i && bitc(rem) <= i) {ans = i;break;}
  }
  printf("%d\n", ans);
  return 0;
}

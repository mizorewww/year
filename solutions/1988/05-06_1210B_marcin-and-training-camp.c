/* Codeforces 1210B - Marcin and Training Camp
 * https://codeforces.com/problemset/problem/1210/B
 * rating: 1700 | tags: brute force, greedy
 * source: accepted submission #61160374 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
 
long long a[100005], b[100005], valid[100005];
 
int main(){
  int n;
  scanf("%d", &n);
 
  int i, j;
  for(i = 0;i < n;i++)scanf("%I64d", a + i);
  for(i = 0;i < n;i++)scanf("%I64d", b + i);
 
  for(i = 0;i < n;i++)valid[i] = 0;
 
  long long ans = 0;
  for(i = 0;i < n;i++)for(j = i + 1;j < n;j++)if(a[i] == a[j]){
        valid[i] = 1;
        valid[j] = 1;
      }

  for(i = 0;i < n;i++)for(j = 0;j < n;j++)if(valid[j])if((a[i]|a[j]) == a[j]){
          ans += b[i];
          break;
  }
  printf("%I64d\n", ans);
  return 0;
}

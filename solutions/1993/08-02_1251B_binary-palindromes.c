/* Codeforces 1251B - Binary Palindromes
 * https://codeforces.com/problemset/problem/1251/B
 * rating: 1400 | tags: greedy, strings
 * source: accepted submission #63316228 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int main(){
  int q;
  scanf("%d", &q);
  while(q--){
    int n, req, i, cnt[2], ans;
    scanf("%d", &n);
    req = 0;
    cnt[0] = cnt[1] = 0;
    for(i = 0;i < n;i++){
      int len;
      char s[51];
      scanf("%s", s);
      for(len = 0;s[len];len++)cnt[s[len] - '0']++;
      if(!(len&1)) req += (len>>1);
    }
    if(req > (cnt[0]>>1) + (cnt[1]>>1)) ans = n - 1;
    else ans = n;
    
    printf("%d\n", ans);
  }
  return 0;
}

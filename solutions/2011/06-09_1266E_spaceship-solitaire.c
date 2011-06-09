/* Codeforces 1266E - Spaceship Solitaire
 * https://codeforces.com/problemset/problem/1266/E
 * rating: 2100 | tags: data structures, greedy, implementation
 * source: accepted submission #67118623 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct __st_pair{
  int f, s;
}pair;

pair ps[100005];
int habe[200005], req[200005], val[100005], n, q, inp[100005][3];

int cmpfn(const void *_a, const void *_b){
  pair *a, *b;
  a = (pair *)_a;
  b = (pair *)_b;
  if(a->f < b->f) return -1;
  if(a->f > b->f) return 1;
  if(a->s < b->s) return -1;
  if(a->s > b->s) return 1;
  return 0;
}

int findr(int f, int s){
  int st, en, m;
  st = 0;en = q - 1;
  while(st < en){
    m = (st + en)>>1;
    if(ps[m].f < f || (ps[m].f == f && ps[m].s < s))st = m + 1;
    else en = m;
  }
  return st;
}

int contrib(int idx){
  int con = req[idx] - habe[idx];
  return con < 0 ? 0 : con;
}

int main(){
  int i, j;
  long long ans = 0;
  scanf("%d", &n);
  for(i = 0;i < n;i++)scanf("%d", req + i);
  scanf("%d", &q);
  for(i = 0;i < q;i++)scanf("%d %d %d", &inp[i][0], &inp[i][1], &inp[i][2]);
  for(i = 0;i < n;i++){
    habe[i] = 0;
    ans += req[i];
  }
  for(i = 0;i < q;i++){
    ps[i].f = inp[i][0];
    ps[i].s = inp[i][1];
    val[i] = -1;
  }
  qsort(ps, q, sizeof(pair), cmpfn);
  for(i = 0;i < q;i++){
    int idx = findr(inp[i][0], inp[i][1]);
    j = val[idx];
    if(j != -1){
      ans -= contrib(j);
      habe[j]--;
      ans += contrib(j);
    }
    j = inp[i][2] - 1;
    val[idx] = j;
    if (j != -1){
      ans -= contrib(j);
      habe[j]++;
      ans += contrib(j);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

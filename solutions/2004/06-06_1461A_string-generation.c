/* Codeforces 1461A - String Generation
 * https://codeforces.com/problemset/problem/1461/A
 * rating: 800 | tags: constructive algorithms, greedy
 * source: accepted submission #100913879 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){int t,i,n,k,j;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  scanf("%d%d",&n,&k);
  for(j=0;j<n;j++)
  {
   printf("%c",j%3+97);
  }
  printf("\n");
 }
 return 0;
}

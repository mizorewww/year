/* Codeforces 926A - 2-3-numbers
 * https://codeforces.com/problemset/problem/926/A
 * rating: 1300 | tags: implementation, math
 * source: accepted submission #36358469 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <math.h>
int main()
{
 int a,b,ans;
 scanf("%d%d",&a,&b);
 for(int i=0;i<=31;i++)
 for(int j=0;j<=19;j++)
 {
  long long tmp=(long long)pow(2,i)*(long long)pow(3,j);
  if(tmp>=a&&tmp<=b) ans++;
 }
 printf("%d\n",ans);
}

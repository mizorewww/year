/* Codeforces 1646B - Quality vs Quantity
 * https://codeforces.com/problemset/problem/1646/B
 * rating: 800 | tags: brute force, constructive algorithms, greedy, sortings, two pointers
 * source: accepted submission #148359432 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
unsigned long long n;
unsigned long long s[300000];
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int t=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
      scanf("%lld",&n);
      for(int j=0;j<n;j++)scanf("%lld",&s[j]);
      qsort(s,n,sizeof(unsigned long long),cmpfunc);
      s[1]=s[0]+s[1];
      for(int m=1;;m++){
          if(n-m<=m){
            printf("NO\n");
            break;
          }
        if(s[n-m]>s[m]){
          printf("YES\n");
          break;
        }
        s[n-m-1]+=s[n-m];
        s[m+1]+=s[m];

      }
    }
    return 0;
}

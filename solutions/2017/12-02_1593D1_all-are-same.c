/* Codeforces 1593D1 - All are Same
 * https://codeforces.com/problemset/problem/1593/D1
 * rating: 1100 | tags: math, number theory
 * source: accepted submission #131833909 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
      int n;
      scanf("%d",&n);
      int arr[n];
      for(int i=0;i<n;i++){
          scanf("%d",&arr[i]);
      }
      qsort(arr, n, sizeof(int), cmpfunc);
      int temp=0;
      for(int i=1;i<n;i++){
          temp = gcd((arr[i]-arr[i-1]),temp);
      }
      if(temp == 0){
          printf("-1\n");
      }
      else{
          printf("%d\n",temp);
      }
    }
    return 0;
}

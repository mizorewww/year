/* Codeforces 1339B - Sorted Adjacent Differences
 * https://codeforces.com/problemset/problem/1339/B
 * rating: 1200 | tags: constructive algorithms, sortings
 * source: accepted submission #76397293 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
      int n,temp;
      scanf("%d",&n);
      int a[n];
      for(int i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      qsort(a, n, sizeof(int), cmpfunc);
      int left=0,right=n-1,b[n],k=0;
      while(k<n)
      {
         b[k]=a[left];
         b[k+1]=a[right];
         k=k+2;
         left++;
         right--;
      }
     for(int i=n-1;i>=0;i--)
     {
         printf("%d ",b[i]);
     }
     printf("\n");
  }
}

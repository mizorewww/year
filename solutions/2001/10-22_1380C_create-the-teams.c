/* Codeforces 1380C - Create The Teams
 * https://codeforces.com/problemset/problem/1380/C
 * rating: 1400 | tags: brute force, dp, greedy, implementation, sortings
 * source: accepted submission #86683234 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );


}

int main()
{
    int t,x,i,j,k,p,s;

     scanf("%d",&t);

     while(t--)
     {
          scanf("%d %d",&x,&k);
          int n[x];

          for(i=0;i<x;i++)
            scanf("%d",&n[i]);

          qsort(n, x, sizeof(int), cmpfunc);

          s=0; p=0;
          for(i=x-1;i>=0;i--)
          {
              if(n[i]>=k) s++;
              else
              {
                  p++;
                  if(n[i]*p>=k) s++,p=0;
              }
          }

          printf("%d\n",s);
     }
}

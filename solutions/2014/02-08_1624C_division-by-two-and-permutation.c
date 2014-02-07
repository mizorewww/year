/* Codeforces 1624C - Division by Two and Permutation
 * https://codeforces.com/problemset/problem/1624/C
 * rating: 1100 | tags: constructive algorithms, flows, graph matchings, greedy, math
 * source: accepted submission #142239740 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,total=0;
        scanf("%d",&n);
        int a[n];
        int check[n+1];
        check[n]=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            check[i]=0;

        }
       

       for(int i=0;i<n;i++)
       {
           int num = a[i];

           while(num!=0)
           {
              
               if(num <= n)
               {
                   if(check[num]==0)
                   {
                       check[num] = 1;
                       a[i] = num ;
                       break;
                   }
               }
               num = num/2;
           }
       }
       for(int i=1;i<n+1;i++)
       {
           if(check[i]==0)
           {
           printf("NO\n");
           break;
           }
           if( i==n )
           printf("YES\n");
       }
    }
    return 0;
}

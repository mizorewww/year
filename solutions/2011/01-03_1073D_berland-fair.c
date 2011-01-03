/* Codeforces 1073D - Berland Fair
 * https://codeforces.com/problemset/problem/1073/D
 * rating: 1700 | tags: binary search, brute force, data structures, greedy
 * source: accepted submission #44868387 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node{
         long long int data;
         struct node*next;
}fair;
int main()
{
    long long int n,t;
    scanf("%I64d %I64d",&n,&t);
    long long int a[n],i,sum=0,min=1e9+1,s=0,ans=0,u;
    for(i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        if(min>a[i])
            min=a[i];
    }
    while(t>=min)
    {
        s=0;sum=0;u=t;
        for(i=0;i<n;i++)
         {
            if(a[i]<=u)
             {
                 sum+=a[i];s++;u-=a[i];
             }
         }
        ans+=s*(t/sum);t%=sum;
    }
     printf("%I64d\n",ans);
}

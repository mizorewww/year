/* Codeforces 33A - What is for dinner?
 * https://codeforces.com/problemset/problem/33/A
 * rating: 1200 | tags: greedy, implementation
 * source: accepted submission #141931 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

#define oo 2000000000
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

long n,m,k;
long a[2005]={0};

int main()
{
 long i;
 long x,y;
 long s=0;
 
 scanf("%ld%ld%ld",&n,&m,&k);
 for(i=1;i<=m;i++)
   a[i]=oo;
 
 for(i=1;i<=n;i++)
   {
    scanf("%ld%ld",&x,&y);
    a[x]=min(a[x],y);
   }
 
 for(i=1;i<=m;i++)
   s+=a[i];
 
 printf("%ld\n",min(s,k));
   
 return 0;
}

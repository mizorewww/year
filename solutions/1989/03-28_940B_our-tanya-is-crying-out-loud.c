/* Codeforces 940B - Our Tanya is Crying Out Loud
 * https://codeforces.com/problemset/problem/940/B
 * rating: 1400 | tags: dp, greedy
 * source: accepted submission #35990196 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
 long long n,b,c,d,k=0;
 scanf("%lld%lld%lld%lld",&n,&b,&c,&d);
 while(1)
 {
  if(n==1)
  break;
        k+=c*(n%b);
        n=n-n%b;
        if(d<c*(n-n/b))
        {
         k+=d;
         n/=b;
  }
  else
  {
   k+=c*(n-1);
   break;
  }
 }
 printf("%lld\n",k);
 return 0;
}
/*code;*/

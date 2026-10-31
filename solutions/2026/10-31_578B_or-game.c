/* Codeforces 578B - "Or" Game
 * https://codeforces.com/problemset/problem/578/B
 * rating: 1700 | tags: brute force, greedy
 * source: accepted submission #13040900 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
u N[222222],L[222222],R[222222];
int main()
{
 u n,k,x,p,i;llu r=0,t;
 scanf("%u%u%u",&n,&k,&x);
 for(p=1;k--;p*=x);
 for(i=0;++i<=n;L[i]|=N[i]|L[i-1])scanf("%u",N+i);
 for(i=n+1;--i;R[i]|=N[i]|R[i+1]);
 for(i=0;++i<=n;)
 {
  t=(N[i]*(llu)p)|L[i-1]|R[i+1];
  if(r<t)r=t;
 }
 printf("%I64u\n",r);
 return 0;
}

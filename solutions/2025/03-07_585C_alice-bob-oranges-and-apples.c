/* Codeforces 585C - Alice, Bob, Oranges and Apples
 * https://codeforces.com/problemset/problem/585/C
 * rating: 2400 | tags: number theory
 * source: accepted submission #13574826 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef long long unsigned llu;
typedef long long ll;
typedef unsigned u;
llu G(llu a,llu b){return b?G(b,a%b):a;}
ll lx,ly;
ll egcd(ll a,ll b)
{
 long long r,q,x=0,y=1;lx=1;ly=0;
 u ee=1;
 while(b!=0)
 {
  q=a/b;
  r=b;b=a%b;a=r;
  r=x;x=lx-q*x;lx=r;
  r=y;y=ly-q*y;ly=r;
  if((ee^=1)&&(q-(b==0)))printf("%I64iB",q-(b==0));
  else if((q-(b==0)))printf("%I64iA",q-(b==0));
 }
 return a;
}
int main()
{
 llu a,b;u i,j,k;
 scanf("%I64u%I64u",&a,&b);
 if(G(a,b)!=1){printf("Impossible\n");return 0;}
 egcd(a,b);
 putchar('\n');
 return 0;
}

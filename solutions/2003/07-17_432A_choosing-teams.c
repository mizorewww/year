/* Codeforces 432A - Choosing Teams
 * https://codeforces.com/problemset/problem/432/A
 * rating: 800 | tags: greedy, implementation, sortings
 * source: accepted submission #19105525 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()

{

int n,i,c=0,k,t;

scanf("%d%d",&n,&k);

for(i=1;i<=n;i++)

{

scanf("%d",&t);

if((k+t)<=5)

c++;

}

printf("%d",c/3);

}

/* Codeforces 46A - Ball Game
 * https://codeforces.com/problemset/problem/46/A
 * rating: 800 | tags: brute force, implementation
 * source: accepted submission #20960319 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main ()
{
int n,c=1,m=2,i=2;
scanf("%d",&n);
printf ("2 ");
while (c<=n-2)
{ 
 m=m+i;
 i=i+1;
 if (m>n)
 {m=m-n;}
 printf("%d ",m);
 c=c+1;
}
return 0;
}

/* Codeforces 1328A - Divisibility Problem
 * https://codeforces.com/problemset/problem/1328/A
 * rating: 800 | tags: math
 * source: accepted submission #74407393 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
long int a,b,t;
scanf("%ld",&t);
while(t--)
{
    scanf("%ld %ld",&a,&b);
    printf("%ld\n",((b-(a%b))%b));
}
return 0;
}

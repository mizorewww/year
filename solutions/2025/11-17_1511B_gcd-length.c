/* Codeforces 1511B - GCD Length
 * https://codeforces.com/problemset/problem/1511/B
 * rating: 1100 | tags: constructive algorithms, math, number theory
 * source: accepted submission #112839074 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <math.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    printf ("%.0f %.0f\n",(pow(10,a-1)+pow(10,c-1)),pow(10,b-1));
}
    return 0;
}

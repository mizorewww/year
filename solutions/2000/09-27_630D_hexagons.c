/* Codeforces 630D - Hexagons!
 * https://codeforces.com/problemset/problem/630/D
 * rating: 1100 | tags: math
 * source: accepted submission #16169877 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>
int main(){
    long long int a,c;
    scanf("%lld",&a);
    c=3*a*(1+a);
    printf("%lld\n",c+1);
    return 0;
}

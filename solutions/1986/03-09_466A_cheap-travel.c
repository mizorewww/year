/* Codeforces 466A - Cheap Travel
 * https://codeforces.com/problemset/problem/466/A
 * rating: 1200 | tags: implementation
 * source: accepted submission #21989849 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>



int main()

{

    int n,m,a,b;

    scanf("%d%d%d%d",&n,&m,&a,&b);

    printf("%d",m*a<b?n*a:n%m*a<b?n/m*b+n%m*a:n/m*b+b);

    return 0;

}

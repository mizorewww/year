/* Codeforces 1332D - Walk on Matrix
 * https://codeforces.com/problemset/problem/1332/D
 * rating: 1700 | tags: bitmasks, constructive algorithms, math
 * source: accepted submission #74995240 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int k=0,n=0;
    scanf("%d",&k);
    printf("3 4\n");
    printf("262143 262143 262143 0\n");
    printf("131072 0 %d 0\n",k);
    printf("262143 262143 262143 %d\n",k);
    return 0;
}

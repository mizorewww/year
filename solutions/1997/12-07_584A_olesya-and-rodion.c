/* Codeforces 584A - Olesya and Rodion
 * https://codeforces.com/problemset/problem/584/A
 * rating: 1000 | tags: math
 * source: accepted submission #13440540 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
    int n, t, i;
    scanf("%d %d", &n, &t);
    if(n==1 && t==10) printf("-1");
    else{
    if(t==10) t=1;
    printf("%d", t);
    for(i=0; i<n-1; i++)
        printf("0");
    }
    return 0;
}

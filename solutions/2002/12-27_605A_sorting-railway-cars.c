/* Codeforces 605A - Sorting Railway Cars
 * https://codeforces.com/problemset/problem/605/A
 * rating: 1600 | tags: constructive algorithms, greedy
 * source: accepted submission #14719262 (GNU C) downloaded from Codeforces
 */

#include "stdio.h"

int n,i,p,mx;
int a[100005];

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&p);
        a[p] = 1+a[p-1];
        if(a[p]>mx) mx = a[p];
    }
    printf("%d\n",n-mx);
}

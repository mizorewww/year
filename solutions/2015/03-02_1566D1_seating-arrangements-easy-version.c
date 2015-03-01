/* Codeforces 1566D1 - Seating Arrangements (easy version) 
 * https://codeforces.com/problemset/problem/1566/D1
 * rating: 1100 | tags: data structures, greedy, sortings
 * source: accepted submission #128647121 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
int a[301];
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    int N=n*m;
    int sum=0;
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<i;j++)
            if(a[j]<a[i]) sum++;
    }
    printf("%d\n",sum);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        solve();
}

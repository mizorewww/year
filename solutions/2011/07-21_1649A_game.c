/* Codeforces 1649A - Game
 * https://codeforces.com/problemset/problem/1649/A
 * rating: 800 | tags: implementation
 * source: accepted submission #148573408 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k=0,m,i,a[101];
        scanf("%d",&n);
        m=n-1;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);

        while(k<m&& a[k+1]==1)
            k++;
        while(a[m-1]==1&& m>k)
            m--;
        printf("%d\n",m-k);
    }
}

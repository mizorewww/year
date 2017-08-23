/* Codeforces 1557A - Ezzat and Two Subsequences
 * https://codeforces.com/problemset/problem/1557/A
 * rating: 800 | tags: brute force, math, sortings
 * source: accepted submission #125384385 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int t;
        long long int sum=0,x=1<<31;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            sum+=t;
            x=x<t?t:x;
        }
        printf("%f\n",1.0*(sum-x)/(n-1)+1.0*x);
    }
    return 0;
}

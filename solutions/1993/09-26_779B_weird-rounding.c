/* Codeforces 779B - Weird Rounding
 * https://codeforces.com/problemset/problem/779/B
 * rating: 1100 | tags: brute force, greedy
 * source: accepted submission #25040820 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==0) {printf("0\n");return 0;}
    int i,ans=0;
    for(i=0;k>0&&n>0;i++)
    {
        if(n%10!=0) ans++;
        else k--;
        n/=10;
    }
    if(n>0) printf("%d\n",ans);
    else printf("%d\n",i-1);
    return 0;
}

/* Codeforces 891A - Pride
 * https://codeforces.com/problemset/problem/891/A
 * rating: 1500 | tags: brute force, dp, greedy, math, number theory
 * source: accepted submission #32396816 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int a[1000005];
int gcd(int a, int b)
{
    while(a%b)
    {
        int t = a%b; a= b; b =t ;
    }
    return b;
}
int dp[2005][2005];
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int one = 0;
    for(i=1;i<=n;i++)
    {
       scanf("%d",&a[i]);
       if(a[i]==1)one++;
    }
    if(one)return printf("%d\n",n-one)*0;
    int j;
    for(i=1;i<=n;i++)dp[i][i] = a[i];
    int len;
    int ans = -1;
    int found = 0;
    for(len=2; len<=n;len++)
    {
        for(i=1;i<=n;i++)
        {
            j = i + len - 1;
            if(j > n)break;
            dp[i][j] = gcd(dp[i][j-1],dp[i+1][j]);
            if(dp[i][j]==1)
            {
                printf("%d\n",len+n-2);
                return 0;
                found = 1;
                break;
            }
        }
        if(found)break;
    }
    printf("-1\n");
    return 0;
}

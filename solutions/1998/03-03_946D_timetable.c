/* Codeforces 946D - Timetable
 * https://codeforces.com/problemset/problem/946/D
 * rating: 1800 | tags: dp
 * source: accepted submission #36134819 (GNU C) downloaded from Codeforces
 */

#include "stdio.h"
const int inf=0x3f3f3f3f;
char clas[505];
int sum[505];
int skip[505][505];
int cost[505][505];
int dp[505];
int MIN(int x,int y)
{
    if(x<y)
        return x;
    else return y;
}
int MAX(int x,int y)
{
    if(x>y)
        return x;
    else return y;
}
int main()
{
    int n,m,k,j,i,p,r,l,mi;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%s",clas+1);
        for(j=1;j<=m;j++)
        {
            if(clas[j]=='1')
                {
                    sum[i]++;
                    skip[i][sum[i]]=j;
                }
        }

        for(p=0;p<=sum[i]-1;p++)
        {
            mi=inf;
            for(l=0;l<=sum[i]-1;l++)
            {
                if(p-l<0)
                    break;
                r=p-l;
                mi=MIN(mi,skip[i][sum[i]-r]-skip[i][l+1]+1);
            }
            cost[i][p]=m-mi;
        }
        cost[i][sum[i]]=m;
    }
    for(i=1;i<=n;i++)
        for(j=k;j>=0;j--)
            for(p=0;p<=MIN(sum[i],j);p++)
        {
            dp[j]=MAX(dp[j],dp[j-p]+cost[i][p]);
        }
    printf("%d\n",n*m-dp[k]);
    return 0;
}

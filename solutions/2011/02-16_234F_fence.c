/* Codeforces 234F - Fence
 * https://codeforces.com/problemset/problem/234/F
 * rating: 1800 | tags: dp
 * source: accepted submission #2367210 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))

int n,r,g,s;
int h[202],d[202],e[202];
int dp[202][40044][2];
int ans;
int main(){
    FILE*IN = fopen("input.txt","r");
    FILE*OUT = fopen("output.txt","w");
    int i,j;
    fscanf(IN,"%d%d%d",&n,&r,&g);

    for(i=0;i<n;i++) fscanf(IN,"%d",h+i);

    for(i=0;i<n-1;i++) d[i] = min(h[i],h[i+1]);

    e[0]=h[0];
    for(i=1;i<n;i++) e[i]=e[i-1]+h[i];
    if(e[n-1]>r+g){
        fprintf(OUT,"-1\n");
        return 0;
    }

    memset(dp,127,sizeof(dp));
    int ng = dp[0][0][0];
    ans = ng;
    if(h[0]<=g) dp[0][0][0]=0;
    if(h[0]<=r) dp[0][h[0]][1]=0;

    for(i=1;i<n;i++){
        for(j=0;j+h[i]<=r;j++){
            //red|red
            dp[i][j+h[i]][1] = min(dp[i][j+h[i]][1],dp[i-1][j][1]);
            //green|red
            dp[i][j+h[i]][1] = min(dp[i][j+h[i]][1],dp[i-1][j][0]+d[i-1]);

            if(i==n-1) ans = min(ans,dp[i][j+h[i]][1]);
        }
        for(j=0;j<=r;j++){
            int tg = e[i] - j;
            if(tg>g) continue;
            //red|green
            dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][1]+d[i-1]);
            //green|green
            dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][0]);

            if(i==n-1) ans = min(ans,dp[i][j][0]);
        }
    }


    fprintf(OUT,"%d\n",ans==ng?-1:ans);
    fclose(IN);
    fclose(OUT);
    return 0;
}

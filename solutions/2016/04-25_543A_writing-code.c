/* Codeforces 543A - Writing Code
 * https://codeforces.com/problemset/problem/543/A
 * rating: 1800 | tags: dp
 * source: accepted submission #19437132 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int n,m,LIM,MOD,ans;

int tot,lst[5010][2];

int f[510][510];

int main()

{

    int i,j,k,x,y;

    scanf("%d%d%d%d",&n,&m,&LIM,&MOD);

    for(i=1;i<=n;i++)

    {

        scanf("%d",&x);

        for(j=1;j<m;j<<=1) { lst[++tot][0] = j; lst[tot][1] = j*x;}

        if(j-1<m) lst[++tot][0] = m-(j-1); lst[tot][1] = lst[tot][0]*x;

    }

    f[0][0] = 1;

    for(i=1;i<=tot;i++) for(j=m;j>=lst[i][0];j--) for(k=LIM;k>=lst[i][1];k--) f[j][k] = (f[j][k]+f[j-lst[i][0]][k-lst[i][1]])%MOD;

    for(i=0;i<=LIM;i++) ans = (ans+f[m][i])%MOD;

    printf("%d",ans);

    return 0;

}

/* Codeforces 407B - Long Path
 * https://codeforces.com/problemset/problem/407/B
 * rating: 1600 | tags: dp, implementation
 * source: accepted submission #17992453 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

#define MOD 1000000007

int n,p[1010];

long long f[1010],sum[1010];

int main()

{

    int i;

    scanf("%d",&n);

    for(i=1;i<=n;i++) scanf("%d",&p[i]);

    for(i=1;i<=n;i++)

    {

        f[i] = (2+sum[i-1]-sum[p[i]-1]+MOD)%MOD;

        sum[i] = (sum[i-1]+f[i])%MOD;

    }

    printf("%I64d",sum[n]);

    return 0;

}

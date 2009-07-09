/* Codeforces 18C - Stripe
 * https://codeforces.com/problemset/problem/18/C
 * rating: 1200 | tags: data structures, implementation
 * source: accepted submission #18072321 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int n,ans,sum[100010];

int main()

{

    int i;

    scanf("%d",&n);

    for(i=1;i<=n;i++)

    {

        scanf("%d",&sum[i]);

        sum[i] += sum[i-1];

    }

    for(i=1;i<n;i++) if(sum[i]*2 == sum[n]) ans++;

    printf("%d",ans);

    return 0;

}

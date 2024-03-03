/* Codeforces 1372C - Omkar and Baseball
 * https://codeforces.com/problemset/problem/1372/C
 * rating: 1500 | tags: constructive algorithms, math
 * source: accepted submission #86556023 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){long long int t,i,j,n,a[200004],s[200004],c;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&n);
        c=0;
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&a[j]);
            if(j!=a[j])
            {
                c++;
                s[c]=j;
            }
        }
        if(c==0)
        {
            printf("0\n");
        }
        else{
        if((s[c]-s[1])==(c-1))
        printf("1\n");
        else
        printf("2\n");
        }
    }
    return 0;
}

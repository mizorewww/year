/* Codeforces 219C - Color Stripe
 * https://codeforces.com/problemset/problem/219/C
 * rating: 1600 | tags: brute force, dp, greedy
 * source: accepted submission #2059302 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#define LIMIT 500005
#define EMPTY -1

char ch[LIMIT][26],a[LIMIT];
int f[LIMIT][26];

int main()
{
    int i,j,k,n,p,t,tmp;

    while (scanf("%d%d%s",&n,&k,a)!=EOF) {
        for (i=0; i<k; ++i)
            f[0][i]=1;
        f[0][a[0]-'A']=0;
        for (i=1; i<n; ++i)
            for (j=0; j<k; ++j) {
                tmp=LIMIT;
                p=EMPTY;
                for (t=0; t<k; ++t)
                    if (t!=j && f[i-1][t]<tmp) {
                        tmp=f[i-1][t];
                        p=t;
                    }
                f[i][j]=tmp+(a[i]!=j+'A');
                ch[i][j]=p+'A';
            }
        tmp=LIMIT;
        p=EMPTY;
        for (i=0; i<k; ++i)
            if (f[n-1][i]<tmp) {
                tmp=f[n-1][i];
                p=i;
            }
        printf("%d\n",tmp);
        a[n-1]=p+='A';
        for (i=1; i<n; ++i)
            a[n-1-i]=p=ch[n-i][p-'A'];
        a[n]='\0';
        puts(a);
    }
    return 0;
}

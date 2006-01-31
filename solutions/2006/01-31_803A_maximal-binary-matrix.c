/* Codeforces 803A - Maximal Binary Matrix
 * https://codeforces.com/problemset/problem/803/A
 * rating: 1400 | tags: constructive algorithms
 * source: accepted submission #26725027 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
int m[100][100];
int main()
{
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    if (k>n*n)return 0*printf("-1\n");
    {
        for (i=0;i<n&&k;i++){
            for (j=i;j<n&&k;j++){
                if (i==j)m[i][i]=1,k--;
                else if (k>1)m[i][j]=m[j][i]=1,k-=2;
            }
        }
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                printf(j?" %d":"%d",m[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}

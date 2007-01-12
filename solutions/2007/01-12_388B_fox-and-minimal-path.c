/* Codeforces 388B - Fox and Minimal path
 * https://codeforces.com/problemset/problem/388/B
 * rating: 1900 | tags: bitmasks, constructive algorithms, graphs, implementation, math
 * source: accepted submission #5886467 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

char g[1001][1001];

int main() {
    int k,z,n=2,i,j,b3[30],len=0,from,prev,y;
    scanf("%d",&k);
    memset(g,'N',sizeof(g));
    z=k;
    while(z) b3[len++]=z%3,z/=3;
    for(i=0;i<len;i++) if(b3[i]) {
        /* create path of length len with b3*3^i possibilities */
        from=0;
        prev=1;
        for(j=0;j<i;j++) {
            for(z=0;z<prev;z++) for(y=0;y<3;y++) g[from+z][n+y]='Y';
            from=n;
            prev=3;
            n+=3;
        }
        for(z=0;z<prev;z++) for(y=0;y<b3[i];y++) g[from+z][n+y]='Y';
        from=n;
        prev=b3[i];
        n+=b3[i];
        for(;j<len-1;j++) {
            for(z=0;z<prev;z++) g[from+z][n]='Y';
            from=n;
            n++;
            prev=1;
        }
        for(z=0;z<prev;z++) g[from+z][1]='Y';
    }
    for(i=0;i<n;i++) for(j=0;j<n;j++) if(g[i][j]=='Y') g[j][i]='Y';
    printf("%d\n",n);
    for(i=0;i<n;i++) {
        g[i][n]=0;
        puts(g[i]);
    }
    return 0;
}

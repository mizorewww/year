/* Codeforces 835C - Star sky
 * https://codeforces.com/problemset/problem/835/C
 * rating: 1600 | tags: dp, implementation
 * source: accepted submission #29072552 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#define WIDTH 100
#define stars(i,j,t) stars[(i-1)+100*(j-1)+100*100*t]

int main()
{
    int n,q,c,i,j,t,bright,x,y,x1,y1,x2,y2,s;
    int stars[110000];
    scanf("%d %d %d",&n,&q,&c);
    
    for(i=1;i<=WIDTH;i++){
        for(j=1;j<=WIDTH;j++){
            for(t=0;t<c+1;t++){
                stars(i,j,t)=0;
            }
        }
    }
    
    for(i=0;i<n;i++){
        scanf("%d %d %d",&x,&y,&s);
        for(t=0;t<c+1;t++){
            stars(x,y,t) += (s+t)%(c+1);
        }
    }
    
    for(i=0;i<q;i++){
        bright=0;
        scanf("%d %d %d %d %d",&t,&x1,&y1,&x2,&y2);
        t = t%(c+1);
        for(x=x1;x<=x2;x++){
            for(y=y1;y<=y2;y++){
                bright+=stars(x,y,t);
            }
        }
        printf("%d\n",bright);
    }
    
    
    return 0;
}

/* Codeforces 1207A - There Are Two Types Of Burgers
 * https://codeforces.com/problemset/problem/1207/A
 * rating: 800 | tags: brute force, greedy, implementation, math
 * source: accepted submission #59291251 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
    int t,a,b,p,f,h,c,r;
    scanf("%d",&t);
    for(a=1;a<=t;a++){
        scanf("%d %d %d %d %d",&b,&p,&f,&h,&c);
        b=b/2;
        if(h<c){r=f;f=p;p=r;r=c;c=h;h=r; }r=0;
        if(p>=b){r=(b*h);b=0;}else{r=(p*h);b-=p; }
        if(f>=b){r+=(b*c);b=0;}else{r+=(f*c);}
        printf("%d\n",r);
    }
    return 0;
}

/* Codeforces 967A - Mind the Gap
 * https://codeforces.com/problemset/problem/967/A
 * rating: 1100 | tags: implementation
 * source: accepted submission #37720601 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
    int i,n,x,h[10000],m[10000],d,t[1200],time;
    scanf("%d%d",&n,&x);
for(i=0;i<n;i++)
{
    scanf("%d%d",&h[i],&m[i]);
    t[i]=h[i]*60+m[i];
}
if((t[0]>x))
{
    printf("0 0");
}
else{
    for(i=1;i<n;i++)
{

    d=t[i]-t[i-1];
    if(d>(2*x+1))
    break;



}

time=t[i-1]+x+1;
printf("%d %d",time/60,time%60);
}
}

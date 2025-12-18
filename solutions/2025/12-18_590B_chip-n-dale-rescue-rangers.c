/* Codeforces 590B - Chip 'n Dale Rescue Rangers
 * https://codeforces.com/problemset/problem/590/B
 * rating: 2100 | tags: binary search, geometry, math
 * source: accepted submission #14004920 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>
int main()
{
    double x1,y1,x2,y2,vm,t,vx,vy,wx,wy;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&vm,&t,&vx,&vy,&wx,&wy);
    double left=0.0,right=1000000000.0;
    while(right-left>1e-8)
    {
        double mid=(left+right)/2;
        double x3,y3;
        if(mid<=t)
        {
            x3=x2-vx*mid;
            y3=y2-vy*mid;
        }
        else
        {
            x3=x2-vx*t-wx*(mid-t);
            y3=y2-vy*t-wy*(mid-t);
        }
        double needt=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))/vm;
        if(needt<=mid)right=mid;
        else left=mid;
    }
    printf("%.12f\n",left);
    return 0;
}

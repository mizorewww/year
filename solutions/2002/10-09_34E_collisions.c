/* Codeforces 34E - Collisions
 * https://codeforces.com/problemset/problem/34/E
 * rating: 2000 | tags: brute force, implementation, math
 * source: accepted submission #149275 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

#define oo 2000000000
#define eps 1e-8
#define abs(a) ((a)<0?-(a):(a))

struct case1
{
 double v,m,x;
}ball[20]={{0,0,0}};

int main()
{
 long n,i,j;
 double cur,final;
 double t=0;
 double temp;
 double m1,m2,v1,v2;
 
 scanf("%ld%lf",&n,&final);
 
 for(i=1;i<=n;i++)
   scanf("%lf%lf%lf",&ball[i].x,&ball[i].v,&ball[i].m);
 
 for(;t<final;)
   {
    cur=final-t;
    for(i=1;i<=n;i++)
      for(j=i+1;j<=n;j++)
        if(abs(ball[i].v-ball[j].v)>eps)
         {
          temp=(ball[i].x-ball[j].x)/(ball[j].v-ball[i].v);
          if(temp>eps&&temp<cur)
           cur=temp;
         }
    for(i=1;i<=n;i++)
      ball[i].x+=ball[i].v*cur;
    for(i=1;i<=n;i++)
      for(j=i+1;j<=n;j++)
        if(abs(ball[i].x-ball[j].x)<=eps)
         {
          m1=ball[i].m;
          m2=ball[j].m;
          v1=ball[i].v;
          v2=ball[j].v;
          ball[i].v=((m1-m2)*v1+2.0*m2*v2)/(m1+m2);
          ball[j].v=((m2-m1)*v2+2.0*m1*v1)/(m1+m2);
         }
    
    t+=cur;
   }
 
 for(i=1;i<=n;i++)
   printf("%.9lf\n",ball[i].x);
 
 return 0;
}

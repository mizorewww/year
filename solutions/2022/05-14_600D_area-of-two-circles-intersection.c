/* Codeforces 600D - Area of Two Circles' Intersection
 * https://codeforces.com/problemset/problem/600/D
 * rating: 2000 | tags: geometry
 * source: accepted submission #18718170 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

#include<stdlib.h>

#include<math.h>

#include<inttypes.h>

int main()

{

 int64_t x1,x2,y1,y2,r1,r2,e,f,h;	

scanf("%" PRId64 "%" PRId64 "%" PRId64,&x1,&y1,&r1);

scanf("%" PRId64 "%" PRId64 "%" PRId64,&x2,&y2,&r2);

long double p,k1,k2,g,pi=3.141592653589793;

e=x2-x1;

f=y2-y1;

if(r1<=r2)

{

h=r1;

g=(long double)(r2-r1);

}

else

{

h=r2;

g=(long double)(r1-r2); 

}

p=sqrtl((long double)(e*e)+(long double)(f*f));

k1=((p*p)+(r1*r1)-(r2*r2))/(2*p);

k2=((p*p)+(r2*r2)-(r1*r1))/(2*p);

if(g>=p)

printf("%.15Lf",(pi*h*h));

else if(p>=(r1+r2))

printf("0.000000000000000");

else

{

long double a2=0;

long double o=2*acosl(k1/r1);

long double a1=(r1*r1*(o-sinl(o)))/2;

a2=a2+a1;

o=2*acosl(k2/r2);

a1=(r2*r2*(o-sinl(o)))/2;

a2=a2+a1;

printf("%.15Lf",a2);

}

}

/* Codeforces 1C - Ancient Berland Circus
 * https://codeforces.com/problemset/problem/1/C
 * rating: 2100 | tags: geometry, math
 * source: accepted submission #19434896 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)
#define SIDE(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define ANGLE(a,b,c) (acos((a*a+b*b-c*c)/(2*a*b)))
#define eps 1e-4

double gcd(double x, double y)
{
    while (fabs(x) > eps && fabs(y) > eps)
    {
        if (x > y)
                x -= floor(x / y) * y;
        else
                y -= floor(y / x) * x;
    }
    return x + y;
}
int main(){
    int x,y,z;
    double x1,y1,x2,y2,x3,y3;
    double a,b,c,A,A2,B,C,R,Area,n;

    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
    a=SIDE(x1,y1,x2,y2);
    b=SIDE(x2,y2,x3,y3);
    c=SIDE(x1,y1,x3,y3);

    A=ANGLE(b,c,a);
    B=ANGLE(a,c,b);
    C=ANGLE(a,b,c);



    n=PI/(gcd(gcd(A,B),C));


    R=a/(2*sin(A));
    Area=n*R*R*sin(2*PI/n)/2;

    printf("%lf\n",Area);
    return 0;
}

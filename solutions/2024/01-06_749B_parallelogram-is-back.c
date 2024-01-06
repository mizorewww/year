/* Codeforces 749B - Parallelogram is Back
 * https://codeforces.com/problemset/problem/749/B
 * rating: 1200 | tags: brute force, constructive algorithms, geometry
 * source: accepted submission #23146444 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()
{
    int x1,y1,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    printf("3\n%d %d\n%d %d\n%d %d\n",x1+x2-x3,y1+y2-y3,x1+x3-x2,y1+y3-y2,x2+x3-x1,y2+y3-y1);
    return 0;
}

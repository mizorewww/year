/* Codeforces 990C - Bracket Sequences Concatenation Problem
 * https://codeforces.com/problemset/problem/990/C
 * rating: 1500 | tags: implementation
 * source: accepted submission #39111887 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long w[1000000];
char s[1000000];

int main()
{
    long long n, i, j, x, y;

    scanf("%I64d", &n);

    for(i=0; i<n; i++)
    {
        scanf("%s", s);
        x=0;
        y=0;
        for(j=0; j<strlen(s); j++)
        {
            if(s[j]=='(')x++;
            else x--;
            if(x<0)
            {
                x=0;
                y++;
            }
        }
        if(x>=0 && y==0) w[300000+x]++;
        if(x==0 && y>0) w[300000-y]++;
    }

    x=0;

    for(i=0; i<=300000; i++)
    {
        x+=w[300000+i]*w[300000-i];
    }

    printf("%I64d\n", x);

    return 0;
}

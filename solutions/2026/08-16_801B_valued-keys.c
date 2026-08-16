/* Codeforces 801B - Valued Keys
 * https://codeforces.com/problemset/problem/801/B
 * rating: 900 | tags: constructive algorithms, greedy, strings
 * source: accepted submission #26420359 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()
{
    char x[101],y[101];

    scanf("%s",x);

    scanf("%s",y);

    int i=0;

    while(x[i])
    {
        if(x[i]<y[i]) break;
        i++;
    }

    if(x[i] == 0) printf(y);
    else printf("-1");
}

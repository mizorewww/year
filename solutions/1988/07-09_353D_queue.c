/* Codeforces 353D - Queue
 * https://codeforces.com/problemset/problem/353/D
 * rating: 2000 | tags: constructive algorithms, dp
 * source: accepted submission #18072197 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

char s[1000010];

int ans;

int main()

{

    int i,j;

    scanf("%s",s+1);

    for(i=1,j=0;s[i];i++) if(s[i] == 'F')

    {

        j++;

        if(i>j) ans = ans+1>i-j?ans+1:i-j;

    }

    printf("%d",ans);

    return 0;

}

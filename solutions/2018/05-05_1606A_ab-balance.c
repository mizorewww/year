/* Codeforces 1606A - AB Balance
 * https://codeforces.com/problemset/problem/1606/A
 * rating: 900 | tags: strings
 * source: accepted submission #133472542 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main()
{   
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        char str[100];
        scanf("%s",&str);
        int sl=strlen(str);
        str[sl-1]=str[0];
        printf("%s\n",str);
    }
    return 0;
}

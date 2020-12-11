/* Codeforces 1450A - Avoid Trygub
 * https://codeforces.com/problemset/problem/1450/A
 * rating: 800 | tags: constructive algorithms, sortings
 * source: accepted submission #100535201 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    return (*(char *)a-*(char *)b);
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        char str[201];
        scanf("%d%s",&n,str);
        qsort(str,n,sizeof(char),cmp);
        printf("%s\n",str);
    }
    return 0;
}

/* Codeforces 448B - Suffix Structures
 * https://codeforces.com/problemset/problem/448/B
 * rating: 1400 | tags: implementation, strings
 * source: accepted submission #7134768 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main()
{
    char a[110],b[110];
    int x[26]={0},y[26]={0};
    int i,j,t=0;
    scanf("%s",a);
    scanf("%s",b);
    for(i=0;a[i]!='\0';i++)
        x[a[i]-'a']++;
    for(i=0;b[i]!='\0';i++)
        y[b[i]-'a']++;
    for(i=0,j=0;a[i]!='\0'&&b[j]!='\0';i++)
        if(b[j]==a[i])
            j++;
    for(i=0;i<26&&b[j]!='\0';i++)
        if(x[i]<y[i])
            break;
        else if(x[i]>y[i])
            t=1;
    if(b[j]=='\0')
        printf("automaton\n");
    else if(t==0&&i==26)
        printf("array\n");
    else if(t==1&&i==26)
        printf("both\n");
    else
        printf("need tree\n");
    return 0;
}

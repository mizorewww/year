/* Codeforces 387C - George and Number
 * https://codeforces.com/problemset/problem/387/C
 * rating: 1700 | tags: greedy, implementation
 * source: accepted submission #5847698 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main()
{
    long int n,m,i,j=0,k=0;
    char s[100005];
    scanf("%s",s);
    for(i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='0')
        {
            j++;
        }
        else
        {
            if((i>0&&i-1<j)||(i-1==j&&s[0]<s[i]))
            {
                k++;break;
            }
            else
            k++;j=0;
        }
    }
    printf("%ld",k);
    return 0;
}

/* Codeforces 1265A - Beautiful String
 * https://codeforces.com/problemset/problem/1265/A
 * rating: 1000 | tags: constructive algorithms, greedy
 * source: accepted submission #66332264 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int i,j,k=0;
    char A[200006];
    scanf("%s",A);
    for(i=0;A[i];i++)
    {
        if(A[i]==A[i+1]&&A[i]!='?')
        {
            k=1;
            break;
        }
        else if(A[i]=='?')
        {
            if(A[i-1]!='a'&&A[i+1]!='a')
            A[i]='a';
            else if(A[i-1]!='b'&&A[i+1]!='b')
            A[i]='b';
             else if(A[i-1]!='c'&&A[i+1]!='c')
            A[i]='c';
        }
   
    }
    if(k==1)
    printf("-1\n");
    else
    printf("%s\n",A);
        }
    return 0;
}

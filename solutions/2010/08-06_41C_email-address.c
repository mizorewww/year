/* Codeforces 41C - Email address
 * https://codeforces.com/problemset/problem/41/C
 * rating: 1300 | tags: expression parsing, implementation
 * source: accepted submission #188168 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>

char a[110],b[100];

int main()
{
    int i,j,alen,flag=0;
    scanf("%s",a);
    alen=strlen(a);
    b[0]=a[0];
    j=1;
    for(i=1;i<alen-3;i++)
    {
        if(!flag&&a[i]=='a'&&a[i+1]=='t'){b[j]='@';flag=1;i++;j++;}
        else if(a[i]=='d'&&a[i+1]=='o'&&a[i+2]=='t'){b[j]='.';j++;i+=2;}
        else {b[j]=a[i];j++;}
    }
    if(i==alen-3&&!flag&&a[i]=='a'&&a[i+1]=='t'){b[j]='@';i+=2;j++;}
    for(;i<alen;i++,j++)b[j]=a[i];
    printf("%s\n",b);
    return 0;
}

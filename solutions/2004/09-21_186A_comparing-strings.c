/* Codeforces 186A - Comparing Strings
 * https://codeforces.com/problemset/problem/186/A
 * rating: 1100 | tags: implementation, strings
 * source: accepted submission #1658918 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()
{
char a[100001],b[100001],c,d;
int i,m;
scanf("%s",a);
scanf("%s",b);

i=0;m=0;
while(a[i]&&b[i])
{
if(a[i]!=b[i])
    {
    if(!m)
        {
        m=1;
        c=a[i];
        d=b[i];
        }
    else
    if(m==1)
        {
        if(c==b[i]&&d==a[i])
            m=2;
        else
            {m=3;break;}
        }
    else
        {m=3;break;}
    } 
i++;   
}
if(m!=2||a[i]||b[i])
    printf("NO\n");
else
    printf("YES");
return 0;    
}

/* Codeforces 581C - Developing Skills
 * https://codeforces.com/problemset/problem/581/C
 * rating: 1400 | tags: implementation, math, sortings
 * source: accepted submission #13268976 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,sl,res,n,k,val,d[10];
    scanf("%d%d",&n,&k);
    res=0;
    for (i=0;i<=9;i++) d[i]=0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&val);
        res+=val/10;
        if (val%10!=0) d[val%10]++;
        d[0]+=((100-val)/10);
    }
    for (i=9;i>=0;i--)
    {
        sl=(10-i)*d[i]<=k?d[i]:k/(10-i);
        k=k-sl*(10-i);
        res+=sl;
    }
    printf("%d",res);
    return 0;
}

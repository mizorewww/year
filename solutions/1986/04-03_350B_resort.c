/* Codeforces 350B - Resort
 * https://codeforces.com/problemset/problem/350/B
 * rating: 1500 | tags: graphs
 * source: accepted submission #4629419 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int a[100005],b[100005],d[100005];
int main()
{
    int n,i,c,k=0,max1=0,hotel;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&c);
        if(c)b[k++]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&c);
        if(d[c])d[c]=3;
        else d[c]=1;
        a[i]=c;
    }
    for(i=0;i<k;i++)
    {
        int count=0,l=b[i];
        while(a[l])
        {
            if(d[a[l]]==3){break;}
            count++;
            l=a[l];
        }
        count+1>max1?(max1=count+1,hotel=b[i]):1;
    }
    for(i=max1-1;i>=0;i--)
    {
        b[i]=hotel;
        hotel=a[hotel];
    }
    printf("%d\n",max1);
    for(i=0;i<max1;i++)
        printf("%d ",b[i]);
    return 0;
}

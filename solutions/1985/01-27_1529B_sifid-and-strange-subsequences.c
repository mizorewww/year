/* Codeforces 1529B - Sifid and Strange Subsequences
 * https://codeforces.com/problemset/problem/1529/B
 * rating: 1100 | tags: greedy, math, sortings
 * source: accepted submission #117214700 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int compare(void *a , void *b)
{ return *(int *)a-*(int *)b;}
int main()
{
    int t; scanf("%d",&t);
    while(t--) {
    int n,min=1000, count=0;
    scanf("%d",&n);
    int a[n],m[n];
    m[0]=0;
    for(int i=0; i<n;i++)
  {  scanf("%d",&a[i]);
      }
    qsort(a,n,sizeof(int),compare);
    min=m[1]=a[1]-a[0];
    for(int i=2;i<n;i++)
    { if(min>a[i]-a[i-1]) min=a[i]-a[i-1];
      m[i]=min;}
    int ans=n;
    for(int i=n-1; i>=0;i--)
    if(a[i]>m[i]) ans--;
    else break;
    if(ans==0) ans=1;
    printf("%d\n",ans);
    }
    return 0;
}

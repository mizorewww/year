/* Codeforces 768D - Jon and Orbs
 * https://codeforces.com/problemset/problem/768/D
 * rating: 2200 | tags: dp, math, probabilities
 * source: accepted submission #24847740 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main(){
    int k,q,p[1000],a[1000],b[1000],i,j,day;
    long double d[1001];
    scanf("%d%d",&k,&q);
    for(i=0;i<q;i++){
        a[i]=i;
        scanf("%d",&p[i]);
        j=i;
        while(j>0 && p[j]<p[j-1]){
            p[j-1]=p[j]+p[j-1];
            p[j]=p[j-1]-p[j];
            p[j-1]=p[j-1]-p[j];
            a[j-1]=a[j]+a[j-1];
            a[j]=a[j-1]-a[j];
            a[j-1]=a[j-1]-a[j];
            j--;
        }
    }
    memset(d,0,sizeof(d));
    d[0]=1;
    day=0;
    for(i=0;i<q;i++){
        while((p[i]-1e-7)/2000>d[k]){
            day++;
            for(j=k;j>=1;j--) d[j]=d[j]*j/k+d[j-1]*(k-j+1)/k;
            d[0]=0;
        }
        b[a[i]]=day;
    }
    for(i=0;i<q;i++) printf("%d\n",b[i]);
}

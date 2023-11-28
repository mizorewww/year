/* Codeforces 1265B - Beautiful Numbers
 * https://codeforces.com/problemset/problem/1265/B
 * rating: 1300 | tags: data structures, implementation, math, two pointers
 * source: accepted submission #66349952 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(){
     int t,i,j,n,m1,m2,k,a[200002];
     scanf("%d",&t);
     while(t--){
        int b[200002]={0};
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&j);
            a[j]=i;
        }
        m1=n;
        m2=0;
        for(i=1;i<n;i++){
            b[a[i]]=1;
            if(a[i]<m1) m1=a[i];
            if(a[i]>m2) m2=a[i];
            if(m2-m1==i-1) printf("1");
            else printf("0");
        }
        printf("1\n");
     }
     return 0;
}

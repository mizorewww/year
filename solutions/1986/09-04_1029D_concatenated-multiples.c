/* Codeforces 1029D - Concatenated Multiples
 * https://codeforces.com/problemset/problem/1029/D
 * rating: 1900 | tags: implementation, math
 * source: accepted submission #42046732 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int search(int *a,int n,int v){
  if(a[0]>v) return 0;
  
  int l=0;
  int r=n;
  while(r-l>1){
    int m=(l+r)/2;
    if(a[m]<=v){
      l=m;
    } else {
      r=m;
    }
  }
  return r;
}

int count(int *a,int n,int v){
  if(v==0) return search(a,n,0);
  return search(a,n,v)-search(a,n,v-1);
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  qsort(a,n,sizeof(int),cmp);
  int *b=(int *)malloc(sizeof(int)*n);
  int64 ans=0;
  int l=0;
  int64 d;
  for(d=10;d<=10000000000LL;d*=10){
    for(i=l;i<n && a[i]<d;i++);
    if(i==l) continue;
    const int r=i;
    for(i=0;i<n;i++) b[i]=d%k*a[i]%k;
    qsort(b,n,sizeof(int),cmp);
    for(i=l;i<r;i++){
      if(a[i]%k==0){
	ans+=count(b,n,0);
      } else {
	ans+=count(b,n,k-a[i]%k);
      }
    }
    for(i=l;i<r;i++){
      if((d+1)%k*a[i]%k==0) ans--;
    }
    l=r;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
}

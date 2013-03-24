/* Codeforces 1027C - Minimum Value Rectangle
 * https://codeforces.com/problemset/problem/1027/C
 * rating: 1600 | tags: greedy
 * source: accepted submission #41774645 (GNU C11) downloaded from Codeforces
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

void run(void){
  int t;
  scanf("%d",&t);
  int *a=(int *)malloc(sizeof(int)*1000000);
  while(t--){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++) scanf("%d",a+i);
    qsort(a,n,sizeof(int),cmp);
    i=0;
    while(a[i]!=a[i+1]) i++;
    int h=a[i];
    double min=100000;
    int minH=0;
    int minW=0;
    i+=2;
    while(i+1<n){
      if(a[i]==a[i+1]){
	double x=(double)a[i]/h;
	if(x+1/x<min){
	  min=x+1/x;
	  minH=h;
	  minW=a[i];
	}
	h=a[i];
	i+=2;
      } else {
	i++;
      }
    }
    printf("%d %d %d %d\n",minH,minH,minW,minW);
  }
}

int main(void){
  run();
  return 0;
}

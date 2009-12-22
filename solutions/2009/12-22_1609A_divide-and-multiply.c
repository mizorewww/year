/* Codeforces 1609A - Divide and Multiply
 * https://codeforces.com/problemset/problem/1609/A
 * rating: 900 | tags: greedy, implementation, math, number theory
 * source: accepted submission #137263421 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i,x;
		scanf("%d",&n);
		long long a[15],sum=0,count=0;
		for(i=0;i<n;i++)scanf("%lld",&a[i]);
		for(i=0;i<n;i++){
			if(a[i]%2==0)
			while(a[i]%2==0){
				a[i]/=2;
				count++;
			}
		}
		long long max=a[0];
		x=0;
		for(i=0;i<n;i++){
			if(a[i]>max){
				max=a[i];
				x=i;
			}
		}
		a[x]=a[x]*pow(2,count);
	    for(i=0;i<n;i++){
	    	sum+=a[i];
		}
		printf("%lld\n",sum);    
    }
    return 0;
}

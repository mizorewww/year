/* Codeforces 628B - New Skateboard
 * https://codeforces.com/problemset/problem/628/B
 * rating: 1300 | tags: dp
 * source: accepted submission #16205812 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
char a[400000];
int main(){
	long long ans=0,i,j,k,n;
	scanf("%s",a);
	n=strlen(a);

	for (i=0;i<n;i++)
		a[i]-='0';
	for (i=0;i<n-1;i++){
		k=a[i]*10+a[i+1];
		if (k%4==0)
			ans+=i+1;
	}
	for (i=0;i<n;i++)
		if (a[i]%4==0) ans++;
	printf("%lld\n",ans);
	return 0;
}

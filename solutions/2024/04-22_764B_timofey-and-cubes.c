/* Codeforces 764B - Timofey and cubes
 * https://codeforces.com/problemset/problem/764/B
 * rating: 900 | tags: constructive algorithms, implementation
 * source: accepted submission #24376090 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int a[200000];
int main()
{
	int n,i;
	
	scanf("%d",&n);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	for (i=0;i<n/2;i+=2){
		int t=0;
		t=a[i];a[i]=a[n-i-1];a[n-i-1]=t;
	}
	for (i=0;i<n;i++) printf("%d ",a[i]);
	
	return 0;
}

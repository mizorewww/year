/* Codeforces 1313C1 - Skyscrapers (easy version)
 * https://codeforces.com/problemset/problem/1313/C1
 * rating: 1500 | tags: brute force, data structures, dp, greedy
 * source: accepted submission #71664663 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

typedef long long LL;
LL min(LL a, LL b){return a<b?a:b;}
LL max(LL a, LL b){return a>b?a:b;}
int m[500000];

int main(){
	int i, j, n, besti, curr;
	LL sum, best=0;
	scanf("%d", &n);
	for(i=0;i<n;++i) scanf("%d", m+i);
	for(i=0;i<n;++i){
		curr=sum=m[i];
		for(j=i-1;j>-1;--j){
			curr=min(m[j], curr);
			sum+=curr;
		}
		curr=m[i];
		for(j=i+1;j<n;++j){
			curr=min(m[j], curr);
			sum+=curr;
		}
		if(sum>best){
			best=sum;
			besti=i;
		}
	}
	for(j=besti-1;j>-1;--j) m[j]=min(m[j], m[j+1]);
	for(j=besti+1;j<n;++j) m[j]=min(m[j], m[j-1]);
	for(i=0;i<n;++i) printf("%d ", m[i]);
	putchar(10);
	return 0;
}

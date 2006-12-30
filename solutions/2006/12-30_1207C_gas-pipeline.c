/* Codeforces 1207C - Gas Pipeline
 * https://codeforces.com/problemset/problem/1207/C
 * rating: 1500 | tags: dp, greedy
 * source: accepted submission #59302967 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>

#define min(a, b) (a<b?a:b)

char s[200001];

void solve(){
	int n, i, j, l, r;
	long long a, b, sum;
	scanf("%d %I64d %I64d %s", &n, &a, &b, s);
	sum=((long long)n)*a+((long long)n+1)*b;//((long long)n-1)*b+2*a;
	for(i=2;i<n-2;++i) if(s[i]=='0' && s[i-1]=='1' && s[i+1]=='1') s[i]='1';
	for(i=0;i<n && s[i]=='0';++i);
	l=i;
	if(l==n){
		printf("%I64d\n", sum);
		return;
	}
	for(i=n-1;i>-1 && s[i]=='0';--i);
	r=i;
	sum+=2*a+(r-l+2)*b;
	for(i=l;i<r;++i){
		j=0;
		while(s[i]=='0' && i<n){
			++j;++i;
		}
		sum+=min(2*a-((long long)j-1)*b, 0);
	}
	printf("%I64d\n", sum);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}

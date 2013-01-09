/* Codeforces 1245C - Constanze's Machine
 * https://codeforces.com/problemset/problem/1245/C
 * rating: 1400 | tags: dp
 * source: accepted submission #64030631 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

typedef long long LL;
const LL mod=1e9+7;
char s[100001];
LL dp[100003][2];

int main(){
	LL pos=1;
	int i, len, j;
	scanf("%s%n", s, &len);
	dp[0][0]=1;
	dp[1][0]=0;
	for(i=0;i<len+1;++i){
		dp[i+1][0]=(dp[i][0]+dp[i][1])%mod;
		dp[i+1][1]=dp[i][0];
	}
	for(i=0;i<len;++i){
		if(s[i]=='m' || s[i]=='w'){
			puts("0");
			return 0;
		}
		j=0;
		while(i+j<len && s[i+j]=='n') ++j;
		if(j) pos=(pos*dp[j--][0])%mod;
		i+=j;
		j=0;
		while(i+j<len && s[i+j]=='u') ++j;
		if(j) pos=(pos*dp[j--][0])%mod;
		i+=j;
	}
	printf("%I64d\n", pos);
	return 0;
}

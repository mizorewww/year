/* Codeforces 1178B - WOW Factor
 * https://codeforces.com/problemset/problem/1178/B
 * rating: 1300 | tags: dp, strings
 * source: accepted submission #57390678 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

char s[1000001];

int main(){
	int len, i;
	long long ws=0, zaklj=0, sum=0;
	char prev=0;
	scanf("%s%n", s, &len);
	for(i=0;i<len;++i){
		if(prev && s[i]=='v'){
			sum+=zaklj;
			++ws;
		}
		if(s[i]=='o'){
			zaklj+=ws;
		}
		prev=s[i]=='v';
	}
	printf("%I64d\n", sum);
	return 0;
}

/* Codeforces 1186C - Vus the Cossack and Strings
 * https://codeforces.com/problemset/problem/1186/C
 * rating: 1800 | tags: implementation, math
 * source: accepted submission #56217189 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#define M 1000005
char strA[M],strB[M];
int C[M];
int main(){
	scanf("%s",strA);
	scanf("%s",strB);
	int n=strlen(strA);
	int m=strlen(strB);
	int num=0,ans=0;
	for(int i=0;i<m;i++){
		num+=strA[i]!=strB[i];
	}
	for(int i=0;i<n-1;i++){
		C[i]=strA[i]!=strA[i+1];
	}
	for(int i=0;i<n-1;i++){
		C[i]=C[i-1]+C[i];
	}
	if(num%2==0)ans++;
	for(int i=m-1;i<n-1;i++){
		num+=C[i]-C[i-m];
		if(num%2==0)ans++;
	}
	printf("%d",ans);
	return 0;
}

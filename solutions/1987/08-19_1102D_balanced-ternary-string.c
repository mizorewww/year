/* Codeforces 1102D - Balanced Ternary String
 * https://codeforces.com/problemset/problem/1102/D
 * rating: 1500 | tags: greedy, strings
 * source: accepted submission #48147883 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int n,i;
	char s[300001];
	int num[3]={0};
	scanf("%d",&n);
	scanf("%s",s);
	for(i=0;i<n;i++)num[s[i]-'0']++;
	for(i=0;i<n;i++){
		if(num[2]>n/3&&s[i]=='2'){
			if(num[0]<n/3){
				num[2]--;
				num[0]++;
				s[i]='0';
			}
			else{
				num[2]--;
				num[1]++;
				s[i]='1';
			}
		}
	}
	for(i=0;i<n;i++){
		if(num[1]>n/3&&s[i]=='1'){
			if(num[0]<n/3){
				num[1]--;
				num[0]++;
				s[i]='0';
			}
		}
	}
	for(i=n-1;i>=0;i--){
		if(num[1]>n/3&&s[i]=='1'){
			if(num[2]<n/3){
				num[1]--;
				num[2]++;
				s[i]='2';
			}
		}
	}
	for(i=n-1;i>=0;i--){
		if(num[0]>n/3&&s[i]=='0'){
			if(num[2]<n/3){
				num[0]--;
				num[2]++;
				s[i]='2';
			}
			else{
				num[0]--;
				num[1]++;
				s[i]='1';
			}
		}
	}
	printf("%s",s);
	return 0;
}

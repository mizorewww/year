/* Codeforces 1301A - Three Strings
 * https://codeforces.com/problemset/problem/1301/A
 * rating: 800 | tags: implementation, strings
 * source: accepted submission #70970141 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int n,i;
	char a[100],b[100],c[100];
	scanf("%d",&n);
	getchar();
	while(n--){
		scanf("%s%s%s",a,b,c);
		for(i=0;c[i]!='\0';i++){
			if(c[i]!=a[i]&&c[i]!=b[i])
			break;
		}
		if(c[i]=='\0')
		printf("YES\n");
		else 
		printf("NO\n");
	}
	return 0;
}

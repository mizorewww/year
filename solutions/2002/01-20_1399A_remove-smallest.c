/* Codeforces 1399A - Remove Smallest
 * https://codeforces.com/problemset/problem/1399/A
 * rating: 800 | tags: greedy, sortings
 * source: accepted submission #88994680 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int t,i,j,b[101];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		for(int k=0;k<101;k++){
			b[k]=0;
		}
		int n,a,flag=0,num=0;
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&a);
			b[a]++;
		}
		for(int k=1;k<101;k++){
			num+=b[k];
			if(num==n)break;
			if(b[k]!=0){
				flag=1;
			}else if(flag){
				break;
			}
		}
		if(num==n)printf("YES\n");
		else{
			printf("NO\n");
		}
	}
 }

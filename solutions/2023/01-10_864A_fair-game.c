/* Codeforces 864A - Fair Game
 * https://codeforces.com/problemset/problem/864/A
 * rating: 1000 | tags: implementation, sortings
 * source: accepted submission #30703670 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main(){
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int c[2], x=a[0], y=-1;
	c[0]=1, c[1]=0;
	for(i=1;i<n;i++){
		if(a[i]==x){
			c[0]++;
		}
		else if(a[i]==y){
			c[1]++;
		}
		else if(y==-1){
			y=a[i];
			c[1]++;
		}
		else{
			break;
		}
	}
	if(c[0]==c[1] && c[0]+c[1]==n){
		printf("YES\n%d %d\n",x,y);
	}
	else{
		printf("NO\n");
	}
	return 0;
}

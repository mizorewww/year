/* Codeforces 1463A - Dungeon
 * https://codeforces.com/problemset/problem/1463/A
 * rating: 1100 | tags: binary search, math
 * source: accepted submission #101568390 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int n,i,a,b,c;
	scanf("%d",&n);
	double t;
	for(i=0;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		t=(a+b+c)/9.0;
		if(((a+b+c)%9==0)&&(t<=a)&&(t<=b)&&(t<=c)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}

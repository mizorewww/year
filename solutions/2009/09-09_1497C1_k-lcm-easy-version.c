/* Codeforces 1497C1 - k-LCM (easy version)
 * https://codeforces.com/problemset/problem/1497/C1
 * rating: 1200 | tags: constructive algorithms, math
 * source: accepted submission #110240403 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,h;
		scanf("%d %d",&n,&k);
		h=n/2;
		if(n%2==0){
			if(h%2==0){
				printf("%d %d %d\n",h,h/2,h/2);
			}
			else{
				printf("%d %d %d\n",2,h-1,h-1);
			}
		}
		else{
			printf("%d %d %d\n",1,h,h);
		}
	}
}

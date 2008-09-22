/* Codeforces 1375A - Sign Flipping
 * https://codeforces.com/problemset/problem/1375/A
 * rating: 1100 | tags: constructive algorithms, math
 * source: accepted submission #85935203 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h> 
 
int main(){
	int t, n, i;
	int a[99];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d", &a[i]);
			if(i % 2 == 0){
				if(a[i] < 0){
					a[i] *= -1;
				}
			}
			else{
				if(a[i] > 0){
					a[i] *= -1;
				}
			}
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	
		
	return 0;
}

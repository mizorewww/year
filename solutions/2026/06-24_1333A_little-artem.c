/* Codeforces 1333A - Little Artem
 * https://codeforces.com/problemset/problem/1333/A
 * rating: 1000 | tags: constructive algorithms
 * source: accepted submission #75859771 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,i,j,k;
		scanf("%d%d",&n,&m);
		printf("W");
		for(i=1;i<m;i++)
			printf("B");
		printf("\n");
		for(i=1;i<n;i++){
			for(j=0;j<m;j++)
				printf("B");
			printf("\n");
		}
	}
	return 0;
}

/* Codeforces 1447B - Numbers Box
 * https://codeforces.com/problemset/problem/1447/B
 * rating: 1000 | tags: greedy, math
 * source: accepted submission #98474898 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>


int abs(int a)
{
		
	return a >= 0 ? a : -a; 
}

int main(){
	
	
	int t;
	scanf("%d",&t);
	
	
	while(t--){
	
		int n,m;
		scanf("%d%d",&n,&m);
		int a[20][20];
		int i,j;
		int minMinus = 100 + 10; 
		int cnt = 0;
		int sum = 0;
		
		for(i = 0;i < n;i++)
			for(j = 0;j < m;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j] < 0) cnt++;
				sum += abs(a[i][j]);
				minMinus = 	minMinus > abs(a[i][j]) ? abs(a[i][j]):minMinus;
			}

		if(cnt % 2 ) sum -= 2 * minMinus; 	
		printf("%d\n",sum);
	}



	return 0;
}

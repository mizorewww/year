/* Codeforces 1490D - Permutation Transformation
 * https://codeforces.com/problemset/problem/1490/D
 * rating: 1200 | tags: dfs and similar, divide and conquer, implementation
 * source: accepted submission #107580235 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

void func(int res[], int A[], int s, int e, int d){
	int i, max, idx;
	if(s>e){
		return;
	}
	else if(s==e){
		res[s]=d;
		return;
	}
	max=0;
	for(i=s; i<=e; ++i){
		if(max<A[i]){
			max=A[i];
			idx=i;
		}
	}
	func(res, A, s, idx-1, d+1);
	res[idx]=d;
	func(res, A, idx+1, e, d+1);
}

int main(void){
	int i, T, N, A[100], res[100];
	
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(i=0; i<N; ++i){
			scanf("%d", A+i);
		}
		func(res, A, 0, N-1, 0);
		for(i=0; i<N; ++i){
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	return 0;
}

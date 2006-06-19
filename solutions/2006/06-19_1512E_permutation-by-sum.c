/* Codeforces 1512E - Permutation by Sum
 * https://codeforces.com/problemset/problem/1512/E
 * rating: 1600 | tags: brute force, greedy, math
 * source: accepted submission #112555005 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
int sig(int n){
	int ans=0;
	for(int i=0; i<n; ++i){
		ans+=i+1;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, l, r, sum, m, sigm, toplus, jpos = 1;
		scanf("%d%d%d%d", &n, &l, &r, &sum);
		m = r-l+1;
		sigm = sig(m);
		//printf("sigm = %d\n", sigm);
		if(sigm<=sum && sum<=sigm+(n-m)*m){
			int arr[n], a2[n+1];
			for(int i=0; i<n+1; ++i){
				a2[i] = 0;
			}
			toplus = sum-sigm;
			for(int i=r-1; i>=l-1; --i){
				if(toplus < (n-m)){
					arr[i] = i-l+2+toplus;
					a2[i-l+2+toplus] = 1;
					toplus = 0;
				}
				else{
					arr[i] = i-l+2+n-m;
					a2[i-l+2+n-m] = 1;
					toplus-=(n-m);
				}	
			}
			for(int i=0; i<l-1; ++i){
				for(int j=jpos; j<n+1; ++j){
					if(a2[j]==0){
						arr[i]=j;
						a2[j]=1;
						jpos = j+1;
						break;
					}
				}
			}
			for(int i=r; i<n; ++i){
				for(int j=jpos; j<n+1; ++j){
					if(a2[j]==0){
						arr[i]=j;
						a2[j]=1;
						jpos = j+1;
						break;
					}
				}
			}
			for(int i=0; i<n; ++i){
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}

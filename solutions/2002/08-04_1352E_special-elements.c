/* Codeforces 1352E - Special Elements
 * https://codeforces.com/problemset/problem/1352/E
 * rating: 1500 | tags: brute force, implementation, two pointers
 * source: accepted submission #79559043 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int arr[8005];

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int i,j;
		long long ans=0;
		int map[8005]={0};
		int vis[8005]={0};
		for(i=1;i<=n;i++){
			scanf("%d",arr+i);
			map[arr[i]]++;
			arr[i]+=arr[i-1];
		}
		for(i=0;i<=n;i++){
			for(j=i+2;j<=n;j++){
				int t=arr[j]-arr[i];
				if(!vis[t]&&t>0&&t<=n){
					ans+=map[t];
					vis[t]=1;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

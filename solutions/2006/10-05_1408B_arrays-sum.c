/* Codeforces 1408B - Arrays Sum
 * https://codeforces.com/problemset/problem/1408/B
 * rating: 1400 | tags: constructive algorithms, greedy, math
 * source: accepted submission #94337772 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,k,a[101],b[1000]={0},dif,ans,i;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[a[i]]++;
		}
		dif=0;
		for(i=0;i<1000;i++)
			if(b[i])
				dif++;
		if(k==1&&dif>1)
			printf("-1\n");
		else if(dif<=k)
			printf("1\n");
		else{
			int ans;
			ans=1;
			ans+=(dif-k)/(k-1);
			if((dif-k)%(k-1))ans++;
			printf("%d\n",ans);
		}
	}
}

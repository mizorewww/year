/* Codeforces 787B - Not Afraid
 * https://codeforces.com/problemset/problem/787/B
 * rating: 1300 | tags: greedy, implementation, math
 * source: accepted submission #25747625 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int main()
{
	int key=0;
	int n,m;
	scanf("%d%d",&n,&m);
	int i,p,j,k;
	for(i=0;i<m;i++)
	{
		scanf("%d",&p);
		if(p==1){
			key=1;
		}
		int a[p];
		for(j=0;j<p;j++)
			scanf("%d",&a[j]);
		int flag=p;
		for(j=0;j<p;j++){
			for(k=0;k<p;k++){
				if(a[j]==-a[k]){
					flag-=1;
					continue;
				}
			}
		}
		if(flag==p){
			key=1;
		}

	}
	if(key==0)
	printf("NO");
	else
		printf("YES");
	

	return 0;
}

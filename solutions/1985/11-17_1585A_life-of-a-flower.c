/* Codeforces 1585A - Life of a Flower
 * https://codeforces.com/problemset/problem/1585/A
 * rating: 800 | tags: implementation
 * source: accepted submission #138877076 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int main(){
	int t,a,b,n,m,i,j,ans,s;
	scanf("%d",&t);
	while(t){
		t--;a=0;b=0;ans=1;s=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			if(a==1&&b==1)ans+=5;
			if(a==1&&b==0)ans+=1;
			if(a==0&&b==0&&i!=1)s=0;
			b=a;
		}
		if(s)printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
/*
4
3
1 0 1
3
0 1 1
4
1 0 0 1
1
0
*/

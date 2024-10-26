/* Codeforces 366A - Dima and Guards
 * https://codeforces.com/problemset/problem/366/A
 * rating: 1100 | tags: implementation
 * source: accepted submission #5215331 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main() {
	int m,i,j,money,a,b,c,d;
	while(scanf("%d",&money)!=EOF) {
		j=-1;
		for(i=1;i<=4;i++) {
			scanf("%d%d%d%d",&a,&b,&c,&d);
			a=a>b?b:a;
			c=c>d?d:c;
			if(money-a>=c)  {
				j=i;
				m=a;
			}

		}
		if(j!=-1)
		printf("%d %d %d\n",j,m,money-m);
		else
			printf("-1\n");
	}
	return 0;
}

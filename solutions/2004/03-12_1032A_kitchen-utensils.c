/* Codeforces 1032A - Kitchen Utensils
 * https://codeforces.com/problemset/problem/1032/A
 * rating: 900 | tags: none
 * source: accepted submission #45921186 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

int main(){
	
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	int en,fre[101],di=0;
	memset(fre,0,sizeof(fre));
	while(x--){
		scanf("%d",&en);
		fre[en]++;
		if(fre[en]>di*y)di++;
	}
	int i,res=0;
	for(i=1;i<=100;i++)if(fre[i])res+=di*y-fre[i];
	printf("%d\n",res);
	
	return 0;
}

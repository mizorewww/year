/* Codeforces 1008B - Turn the Rectangles
 * https://codeforces.com/problemset/problem/1008/B
 * rating: 1000 | tags: greedy, sortings
 * source: accepted submission #40271219 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main(){
	
	int n,b=1,w,h,ah,bu;
	scanf("%d",&n);
	n--;
	scanf("%d %d",&w,&h);
	ah=w;
	if(h>w)ah=h;
	while(n--){
		scanf("%d %d",&w,&h);
		if(w>h){
			bu=w;
			w=h;
			h=bu;
		}
		if(h<=ah){
			ah=h;
		}
		else if(w<=ah){
			ah=w;
		}
		else{
			b=0;
		}
	}
	if(b)printf("YES\n");
	else printf("NO\n");
	
	return 0;
}

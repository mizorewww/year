/* Codeforces 373B - Making Sequences is Fun
 * https://codeforces.com/problemset/problem/373/B
 * rating: 1600 | tags: binary search, implementation, math
 * source: accepted submission #5429341 (GNU C) downloaded from Codeforces
 */

# include <stdio.h> 
# include <math.h>
int main(){
	long long int w,m,k,g,A[30],B[30],i,c,d,l=0;
	w=10;
	A[0]=0;
	B[0]=0;
	for(i=1;i<19;i++){
		A[i]=w-1;
		B[i]=w;
		w*=10;
	}
	scanf("%I64d%I64d%I64d",&w,&m,&k);
	c=w;
	d=m;
	g=log10(m)+1;
	while(c>0){
		if(((double)c/(double)g)/(double)k>=A[g]-m+1){ 
			c=c-k*g*(A[g]-m+1);
			l=l+A[g]-m+1;
			m=B[g];
			g=log10(m)+1;
		}
		else{
			l=l+((double)c/(double)g)/(double)k;
			break;
		}
	}
	printf("%I64d\n",l);
	return 0;
}

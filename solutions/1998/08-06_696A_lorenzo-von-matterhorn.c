/* Codeforces 696A - Lorenzo Von Matterhorn
 * https://codeforces.com/problemset/problem/696/A
 * rating: 1500 | tags: brute force, data structures, implementation, trees
 * source: accepted submission #19180377 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

#include<string.h>

#define N 165003

long long key[N];

long long val[N];

long long calc(long long x){

	long long val = x%N;

	while(key[val] && key[val]!=x){

		val++;

		if(val>N)

		val=1;

	}

	key[val]=x;

	return val;

}

long long swap(long long *a,long long *b){

	long long temp  = *a;

	*a=*b;

	*b=temp;

}

long long lca(long long v, long long u, long long int w){

	if(u==v)

		return 0;

	if(u<v)

		swap(&u,&v);

	val[calc(u)]+=w;

	return lca(v,u/2,w) + val[calc(u)];

}

int main(){

	long long a,b,c,d,e;

	scanf("%lld",&a);

	long long i;

	for(i=0;i<a;i++){

		long long in,in1,in2,in3;

		scanf("%lld%lld%lld",&in,&in1,&in2);

		if(in==1){

			scanf("%lld",&in3);

			lca(in1,in2,in3);

		}

		else{

			printf("%lld\n",lca(in1,in2,0));

		}

	}

	

}

/* Codeforces 1398D - Colored Rectangles
 * https://codeforces.com/problemset/problem/1398/D
 * rating: 1800 | tags: dp, greedy, sortings
 * source: accepted submission #89948965 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int R, G, B, p, c, x, Rsize, Gsize, Bsize, idx, tmp, Rheap[201], Gheap[201], Bheap[201];
int dp[201][201][201];

long long dfs(){
	long long ttmp, res=0;
	int Rrm, Grm, Brm;
	
	if(dp[Rsize][Gsize][Bsize]){
		return dp[Rsize][Gsize][Bsize];
	}
	
	if(Rsize && Gsize){
		Rrm=Rheap[1];
		tmp=Rheap[Rsize--];
		
		p=1;
		c=2;
		while(c<=Rsize){
			if((c<Rsize) && (Rheap[c]<Rheap[c+1])){
				++c;
			}
			
			if(tmp>=Rheap[c]){
				break;
			}
			
			Rheap[p]=Rheap[c];
			p=c;
			c*=2;
		}
		Rheap[p]=tmp;
		
		Grm=Gheap[1];
		tmp=Gheap[Gsize--];
		
		p=1;
		c=2;
		while(c<=Gsize){
			if((c<Gsize) && (Gheap[c]<Gheap[c+1])){
				++c;
			}
			
			if(tmp>=Gheap[c]){
				break;
			}
			
			Gheap[p]=Gheap[c];
			p=c;
			c*=2;
		}
		Gheap[p]=tmp;
		
		
		res=Rrm*Grm+dfs();
		
		
		x=Rrm;
		idx=++Rsize;
		while((idx-1) && (x>Rheap[idx/2])){
			Rheap[idx]=Rheap[idx/2];
			
			idx=idx/2;
		}
		Rheap[idx]=x;
		
		x=Grm;
		idx=++Gsize;
		while((idx-1) && (x>Gheap[idx/2])){
			Gheap[idx]=Gheap[idx/2];
			
			idx=idx/2;
		}
		Gheap[idx]=x;
	}
	if(Gsize && Bsize){
		Grm=Gheap[1];
		tmp=Gheap[Gsize--];
		
		p=1;
		c=2;
		while(c<=Gsize){
			if((c<Gsize) && (Gheap[c]<Gheap[c+1])){
				++c;
			}
			
			if(tmp>=Gheap[c]){
				break;
			}
			
			Gheap[p]=Gheap[c];
			p=c;
			c*=2;
		}
		Gheap[p]=tmp;
		
		Brm=Bheap[1];
		tmp=Bheap[Bsize--];
		
		p=1;
		c=2;
		while(c<=Bsize){
			if((c<Bsize) && (Bheap[c]<Bheap[c+1])){
				++c;
			}
			
			if(tmp>=Bheap[c]){
				break;
			}
			
			Bheap[p]=Bheap[c];
			p=c;
			c*=2;
		}
		Bheap[p]=tmp;
		
		
		ttmp=Grm*Brm+dfs();
		
		
		x=Grm;
		idx=++Gsize;
		while((idx-1) && (x>Gheap[idx/2])){
			Gheap[idx]=Gheap[idx/2];
			
			idx=idx/2;
		}
		Gheap[idx]=x;
		
		x=Brm;
		idx=++Bsize;
		while((idx-1) && (x>Bheap[idx/2])){
			Bheap[idx]=Bheap[idx/2];
			
			idx=idx/2;
		}
		Bheap[idx]=x;
		
		if(res<ttmp){
			res=ttmp;
		}
	}
	if(Bsize && Rsize){
		Brm=Bheap[1];
		tmp=Bheap[Bsize--];
		
		p=1;
		c=2;
		while(c<=Bsize){
			if((c<Bsize) && (Bheap[c]<Bheap[c+1])){
				++c;
			}
			
			if(tmp>=Bheap[c]){
				break;
			}
			
			Bheap[p]=Bheap[c];
			p=c;
			c*=2;
		}
		Bheap[p]=tmp;
		
		Rrm=Rheap[1];
		tmp=Rheap[Rsize--];
		
		p=1;
		c=2;
		while(c<=Rsize){
			if((c<Rsize) && (Rheap[c]<Rheap[c+1])){
				++c;
			}
			
			if(tmp>=Rheap[c]){
				break;
			}
			
			Rheap[p]=Rheap[c];
			p=c;
			c*=2;
		}
		Rheap[p]=tmp;
		
		
		ttmp=Brm*Rrm+dfs();
		
		
		x=Brm;
		idx=++Bsize;
		while((idx-1) && (x>Bheap[idx/2])){
			Bheap[idx]=Bheap[idx/2];
			
			idx=idx/2;
		}
		Bheap[idx]=x;
		
		x=Rrm;
		idx=++Rsize;
		while((idx-1) && (x>Rheap[idx/2])){
			Rheap[idx]=Rheap[idx/2];
			
			idx=idx/2;
		}
		Rheap[idx]=x;
		
		if(res<ttmp){
			res=ttmp;
		}
	}
	dp[Rsize][Gsize][Bsize]=res;
	
	return res;
}

int main(void){
	int i;
	long long res;
	
	scanf("%d %d %d", &R, &G, &B);
	
	for(i=0; i<R; ++i){
		scanf("%d", &x);
		
		idx=++Rsize;
		
		while((idx-1) && (x>Rheap[idx/2])){
			Rheap[idx]=Rheap[idx/2];
			
			idx=idx/2;
		}
		
		Rheap[idx]=x;
	}
	for(i=0; i<G; ++i){
		scanf("%d", &x);
		
		idx=++Gsize;
		
		while((idx-1) && (x>Gheap[idx/2])){
			Gheap[idx]=Gheap[idx/2];
			
			idx=idx/2;
		}
		
		Gheap[idx]=x;
	}
	for(i=0; i<B; ++i){
		scanf("%d", &x);
		
		idx=++Bsize;
		
		while((idx-1) && (x>Bheap[idx/2])){
			Bheap[idx]=Bheap[idx/2];
			
			idx=idx/2;
		}
		
		Bheap[idx]=x;
	}
	res=dfs();
	printf("%lld", res);
	
	return 0;
}

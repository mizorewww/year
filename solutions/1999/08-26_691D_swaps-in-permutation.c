/* Codeforces 691D - Swaps in Permutation
 * https://codeforces.com/problemset/problem/691/D
 * rating: 1700 | tags: dfs and similar, dsu, math
 * source: accepted submission #19091206 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct __st_LL{
    int val;
    struct __st_LL *next;
}LL;

int getp(int x);
void join(int a, int b);
void append(int ind, int val);
int rem(int ind);

LL *grl[1000006];
int par[1000006], grmap[1000006], ngr, n, m, ar[1000006], grp[1000006];

int main(){
    int i, j, k;
    for(i=0;i<1000006;i++){
	grl[i] = NULL;
	par[i] = -1;
	grmap[i] = -1;
    }
    ngr = 0;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++){
	scanf("%d", ar+i);
    }
    for(i=0;i<m;i++){
	scanf("%d %d", &j, &k);
	j--;
	k--;
	join(j, k);
    }
    for(i=0;i<n;i++){
	j = getp(i);
	if(grmap[j] == -1){
	    grmap[j] = ngr++;
	}
	grp[ar[i]] = grmap[j];
    }
    for(i=1;i<=n;i++){
	j = grp[i];
	append(j, i);
    }
    for(i = 0;i<n;i++){
	j = getp(i);
	printf("%d ", rem(grmap[j]));
    }
    printf("\n");
    return 0;
}

int getp(int x){
    if(par[x] < 0){
	return x;
    }
    par[x] = getp(par[x]);
    return par[x];
}

void join(int a, int b){
    int pa, pb;
    pa = getp(a);
    pb = getp(b);
    if(pa == pb)
	return ;
    if(par[pa] < par[pb])
	par[pb] = pa;
    else if(par[pa] > par[pb])
    	par[pa] = pb;
    else{
	par[pb] = pa;
	par[pa]--;
    }
}

void append(int ind, int val){
    LL *temp = (LL *)malloc(sizeof(LL));
    temp->next = grl[ind];
    temp->val = val;
    grl[ind] = temp;
}

int rem(int ind){
    int toret;
    if(grl[ind] == NULL){
	while(1>0){
	    1+2;
	}
    }
    toret = grl[ind]->val;
    grl[ind] = grl[ind]->next;
    return toret;
}

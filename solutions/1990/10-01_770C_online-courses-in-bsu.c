/* Codeforces 770C - Online Courses In BSU
 * https://codeforces.com/problemset/problem/770/C
 * rating: 1500 | tags: *special, dfs and similar, graphs, implementation
 * source: accepted submission #25414761 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

int m[100000];
int* g[100000+1];
int gn[100000+1];

int q[100000];
int qn=0;

int skill[100000+1];
int used[100000+1];

int dfs(int v){
    if (skill[v])
        return 0;
    
    if (used[v])
        return 1;
    used[v]=1;
    
    for (int i=0; i<gn[v]; i++)
        if (dfs(g[v][i]))
            return 1;
    
    skill[v]=1;
    q[qn++]=v;
    
    used[v]=0;
    return 0;
}

int main(){
    
    for (int i=0; i<100000+1; i++){
        used[i]=0;
        skill[i]=0;
    }
    
    int n, k;
    scanf("%d %d",&n,&k);
    for (int i=0; i<k; i++)
        scanf("%d",m+i);
    for (int i=1; i<=n; i++){
        scanf("%d",gn+i);
        g[i]=(int*)malloc(sizeof(int)*gn[i]);
        for (int ii=0; ii<gn[i]; ii++)
            scanf("%d", g[i]+ii);
    }
    
    for (int i=0; i<k; i++)
        if (dfs(m[i])){
            printf("-1");
            return 0;
        }
    
    printf("%d\n",qn);
    for (int i=0; i<qn; i++)
        printf("%d ",q[i]);
    
    return 0;
}

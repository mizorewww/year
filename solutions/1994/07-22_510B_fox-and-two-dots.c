/* Codeforces 510B - Fox And Two Dots
 * https://codeforces.com/problemset/problem/510/B
 * rating: 1500 | tags: dfs and similar
 * source: accepted submission #9685323 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int DIR[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int R,C;
char map[50][51];
int taken[50][50];

int MLX(int r, int c, int last) {
  int i,nr,nc;
  taken[r][c]=1;
  //printf("%d %d\n", r+1,c+1);
  for(i=0;i<4;i++) if(last==-1 || ((i-last+4)%4 != 2)) {
    nr=r+DIR[i][0];
    nc=c+DIR[i][1];
    //printf("    %d %d\n", nr+1,nc+1);
    if(nr>=0 && nr<R && nc>=0 && nc<C && map[nr][nc]==map[r][c]) {
      if(taken[nr][nc]) return 1;
      else if(MLX(nr,nc,i)) return 1;
    }
    }
  return 0;
}

int main() {
  int i,j;
  scanf("%d %d", &R,&C);
  for(i=0;i<R;i++) {
    scanf("%s", map[i]);
  }
  for(i=0;i<R;i++) for(j=0;j<C;j++) taken[i][j]=0;
  for(i=0;i<R;i++) for(j=0;j<C;j++) if(!taken[i][j] && MLX(i,j,-1)) {
	printf("Yes\n");
	return 0;
      }
  printf("No\n");
  return 0;
}

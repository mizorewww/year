/* Codeforces 42B - Game of chess unfinished
 * https://codeforces.com/problemset/problem/42/B
 * rating: 1700 | tags: implementation
 * source: accepted submission #198542 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

#define W_L 1
#define W_K 2
#define B_K -4

void set_p(int board[8][8]){
   int i,j,k,l;

   for(i = 0; i<8; i++)
      for(j = 0; j<8; j++)
	 if(!(board[i][j]>0 || board[i][j]==B_K))
	    board[i][j]=0;

   for(i = 0; i<8; i++)
      for(j = 0; j<8; j++)
	 if(board[i][j]>0){
	    if(board[i][j]==W_L){
	       for(k = j-1; k>=0 && board[i][k]<=0;k--)
		  board[i][k]=-1;
	       for(k = j+1; k<8 && board[i][k]<=0; k++)
		  board[i][k]=-1;
	       for(k = i-1; k>=0 && board[k][j]<=0;k--)
		  board[k][j]=-1;
	       for(k = i+1; k<8 && board[k][j]<=0; k++)
		  board[k][j]=-1;
	    } else if(board[i][j]==W_K) {
	      for(k = i-1; k<=i+1; k++)
		 for(l = j-1; l<=j+1; l++)
		    if(k>=0 && k<8 && l>= 0 && l<8 && board[k][l]<=0)
		       board[k][l]=-1; 
	    }
	 }

}

void cpy_board(int dest[8][8], int source[8][8]){
   int i,j;
   for(i = 0; i<8; i++)
      for(j = 0; j<8; j++)
	 dest[i][j] = source[i][j];
}

int main(){
   int x,y;
   char _x;
   int i, j;
   int other = 0;
   int board[8][8];
   int temp_board[8][8];

   for(i = 0; i<8; i++)
      for(j = 0; j<8; j++)
	 board[i][j] = 0;

   scanf("%c%d ",&_x,&y);
      x = _x-'a';
      y--;
   board[x][y] = W_L;
   scanf("%c%d ",&_x,&y);
      x = _x-'a';
      y--;
   board[x][y] = W_L;
   scanf("%c%d ",&_x,&y);
      x = _x-'a';
      y--;
   board[x][y] = W_K;
   scanf("%c%d",&_x,&y);
      x = _x-'a';
      y--;
   board[x][y] = B_K;

   set_p(board);

   if(board[x][y] == B_K)
      printf("OTHER\n");
   else {
      other = 0;
      for(i = x-1; i<=x+1; i++)
	 for(j = y-1; j<=y+1; j++){
	    if(i>=0 && i<8 && j>=0 && j<8)
	       if(board[i][j]==0)
		  other = 1;
	    if(i>=0 && i<8 && j>=0 && j<8 && board[i][j]==W_L){
	       cpy_board(temp_board, board);
	       temp_board[x][y]=0;
	       temp_board[i][j]=B_K;
	       set_p(temp_board);
	       other = other || (temp_board[i][j]==B_K);
	    }
	 }
      if(other)
	 printf("OTHER\n");
      else
	 printf("CHECKMATE\n");

   }
   return 0;
}

/* Codeforces 336C - Vasily the Bear and Sequence
 * https://codeforces.com/problemset/problem/336/C
 * rating: 1800 | tags: brute force, greedy, implementation, number theory
 * source: accepted submission #4254905 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main(void){
  unsigned int seq[(int)1E5];
  int n,i,j,k,bit=0,nowbit=-1,tmp,num=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%u",seq+i);
  
  for(bit=0;bit<31 && (1<<bit)<=seq[n-1] ;bit++){
    for(i=0; i<n && seq[i]<(1<<bit) ;i++);
    for(tmp=seq[j=i];j<n;++j) if(seq[j]<(unsigned int)(1<<(bit+1)) || ((seq[j]>>bit)&1)) tmp&=seq[j];
    if(tmp%(1<<bit)==0) nowbit=bit,k=i;
  }

  if(nowbit!=-1){
    for(i=k;i<n;i++) if(seq[i]<(unsigned int)(1<<(nowbit+1)) || ((seq[i]>>nowbit)&1)) num++;
    printf("%d\n",num);
    for(i=k;i<n;i++){
      if(seq[i]<(unsigned int)(1<<(nowbit+1)) || ((seq[i]>>nowbit)&1)){
	num--;
	printf("%d%c",seq[i],(num==0)?'\n':' ');
      }
    }
  }else{
    printf("%d\n",n);
    for(i=0;i<n;i++) printf("%d%c",seq[i],(i==n-1)?'\n':' ');
  }
  return 0;
}

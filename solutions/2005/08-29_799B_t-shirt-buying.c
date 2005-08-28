/* Codeforces 799B - T-shirt buying
 * https://codeforces.com/problemset/problem/799/B
 * rating: 1400 | tags: data structures, implementation
 * source: accepted submission #27032552 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>

struct Shirt{
	int price;
	int front;
	int back;
};

int comp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int n,m,i,j,flag,count=0,x=0,y=0,z=0;
	scanf("%d",&n);
	struct Shirt shirt[n];
	for(i=0;i<n;i++){
		scanf("%d",&shirt[i].price);
	}
	for(i=0;i<n;i++){
		scanf("%d",&shirt[i].front);
	}
	for(i=0;i<n;i++){
		scanf("%d",&shirt[i].back);
	}
	scanf("%d",&m);
	int input[m];
	for(i=0;i<m;i++){
		scanf("%d",&input[i]);
	}
	qsort(shirt,n,sizeof(struct Shirt),comp);
	for(i=0;i<m;i++){
		flag=0;
		if(count>=n){
			printf("-1 ");
		}
        else if(input[i]==1){
        	while(x<n){
        		if(shirt[x].front==1||shirt[x].back==1){
        			printf("%d ",shirt[x].price);
        			shirt[x].front=0;
        			shirt[x].back=0;
        			count++;
        			flag=1;
        			break;
        		}
        		x++;
        	}
        	if(flag==0){
        		printf("-1 ");
        	}
        }
        else if(input[i]==2){
        	while(y<n){
        		if(shirt[y].front==2||shirt[y].back==2){
        			printf("%d ",shirt[y].price);
        			shirt[y].front=0;
        			shirt[y].back=0;
        			count++;
        			flag=1;
        			break;
        		}
        		y++;
        	}
        	if(flag==0){
        		printf("-1 ");
        	}
        }
        else if(input[i]==3){
        	while(z<n){
        		if(shirt[z].front==3||shirt[z].back==3){
        			printf("%d ",shirt[z].price);
        			shirt[z].front=0;
        			shirt[z].back=0;
        			count++;
        			flag=1;
        			break;
        		}
        		z++;
        	}
        	if(flag==0){
        		printf("-1 ");
        	}
        }
	}
	return 0;
}

/* Codeforces 12C - Fruits
 * https://codeforces.com/problemset/problem/12/C
 * rating: 1100 | tags: greedy, implementation, sortings
 * source: accepted submission #52165 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#define STRMAX 50

struct fruit{
	int num;
	char name[STRMAX];
};

int compare_intup(const int *a, const int *b)
{
    return *a - *b;
}

int compare_intdown(const int *a, const int *b)
{
    return *b - *a;
}

int compare_listint(const struct fruit *a, const struct fruit *b)
{
	return b->num - a->num;
}

int main(void){
	int mintags[100],maxtags[100],tags[100];
	int n,m,i,j,k,flag;
	unsigned long int min,max;
	struct fruit list[100];
	char str[STRMAX];
	
	for(i=0;i<100;i++){
		list[i].num=0;
		memset(list[i].name,'\0',STRMAX);
	}
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n-1;i++){
		scanf("%d ",&(tags[i]));
	}
	scanf("%d",&(tags[i]));
	k=0;
	for(i=0;i<m;i++){
		memset(str,'\0',STRMAX);
		flag=0;
		scanf("%s",str);
		for(j=0;j<k;j++){
			if(strcmp(list[j].name,str)==0){
				list[j].num++;
				flag=1;
			}
		}
		if(flag==0){
			strcpy(list[k].name,str);
			list[k].num++;
			k++;
		}
	}
	qsort(list, k, sizeof(struct fruit), (int (*)(const void*, const void*))compare_listint);
	min=0;
	max=0;
	qsort(tags, n, sizeof(int), (int (*)(const void*, const void*))compare_intup);
	for(i=0;i<k;i++){
		max+=tags[i]*list[i].num;
	}
	qsort(tags, n, sizeof(int), (int (*)(const void*, const void*))compare_intdown);
	for(i=0;i<k;i++){
		min+=tags[i]*list[i].num;
	}
	
	
	printf("%lu %lu\n",max,min);
	return 0;
}

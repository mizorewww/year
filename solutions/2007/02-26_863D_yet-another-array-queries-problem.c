/* Codeforces 863D - Yet Another Array Queries Problem
 * https://codeforces.com/problemset/problem/863/D
 * rating: 1800 | tags: data structures, implementation
 * source: accepted submission #30592736 (GNU C) downloaded from Codeforces
 */

/*
n, q, m = [int(st) for st in input().split(" ")]
a = [int(st) for st in input().split(" ")]
segs = []
for i in range(q):
    segs.append([int(st) for st in input().split(" ")])
b = [int(st)-1 for st in input().split(" ")]

for i in range(len(b)):
    
    index = b[i]

    #print("")
    for j in range(q-1, -1, -1):

        #print("Index changed to ", index, end = " ->")
        seg = segs[j]
        l = seg[1]-1
        r = seg[2]-1
        
        if seg[0] == 1: # 1 l r
            if index == l:
                index = r
            elif index in range(l+1, r+1):
                index -= 1

        else: # 2 l r
            if index in range(l, r+1):
                index = r - (index-l)

        #print(index)
    
    print(a[index], end = " ")
*/

#include <stdio.h>

int a[200005] = {0,};
int seg[200005][3] = {0,};
int b[105] = {0,};

int main(void){
	
	int n, q, m;
	int i, j;
	
	scanf("%d %d %d", &n, &q, &m);
	
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<q; i++){
		scanf("%d %d %d", &seg[i][0], &seg[i][1], &seg[i][2]);
	}
	for(i=0; i<m; i++){
		scanf("%d", &b[i]);
		b[i] -= 1;
	}
	
	for(i=0; i<m; i++){
		int index = b[i];
		for(j=q-1; j>=0; j--){
			int l = seg[j][1] - 1;
			int r = seg[j][2] - 1;
			
			if(seg[j][0] == 1){
				if(index == l){
					index = r;
				}
				else if(l+1<=index && index <=r){
					index -= 1;
				}
			}
			else{
				if(l<=index && index<=r){
					index = r-(index-l);
				}
			}
		}
		printf("%d ", a[index]);
	}

	
	return 0;
}

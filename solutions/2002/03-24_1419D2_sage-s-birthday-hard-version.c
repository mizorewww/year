/* Codeforces 1419D2 - Sage's Birthday (hard version)
 * https://codeforces.com/problemset/problem/1419/D2
 * rating: 1500 | tags: binary search, brute force, constructive algorithms, greedy, sortings, two pointers
 * source: accepted submission #93265678 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comp(const void* a, const void* b){
	return ( *(int*)a - *(int*)b );
}

int main(void) {
    int n;
    scanf("%d", &n);

    int* a = (int*) malloc(n * sizeof(int));
    int* b = (int*) malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), comp);
    int j = n/2;
    int k = 0;
    for(int i=0;n % 2 != 0 || i < n/2;i++){
		b[k++] =a[j];
		j++;
		if (i == j / 2) {
			break;
		}
		b[k++] = a[i];
    }
    int c = 0;
    for(int i = 1; i<n;i+=2){
		if (b[i] < b[i - 1] && (i+1 != n && b[i + 1] > b[i])){
			++c;
		}
    }
	printf("%d\n", c);
    for(int i = 0; i<n;i++){
		printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}

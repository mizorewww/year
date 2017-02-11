/* Codeforces 1017C - The Phone Number
 * https://codeforces.com/problemset/problem/1017/C
 * rating: 1600 | tags: constructive algorithms, greedy
 * source: accepted submission #41351417 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int* array;

int main(){
    int n;
    scanf("%d\n", &n);
	
	int s = (int)ceil(sqrt(n));
	int m = s * s;
	
	array = (int*)malloc(m * sizeof(int));
	int i, j, a;
	for (i = 0; i < s; i ++)
		for (j = 0; j < s; j ++) {
			a = i + ((s - j - 1) * s);
			if (a < n) printf("%d ", a + 1);
		}
}

/* Codeforces 1141C - Polycarp Restores Permutation
 * https://codeforces.com/problemset/problem/1141/C
 * rating: 1500 | tags: math
 * source: accepted submission #51532776 (GNU C11) downloaded from Codeforces
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void no()
{
	printf("-1");
	exit(0);
}

int main() {
    int n, q[300000], a[300000], b[300000], i, min = 100000000;
    scanf("%d", &n);
    for(i = 1; i < n; i++) {
    	scanf("%d", &(q[i]));
    	if(i > 1) {
    		q[i] += q[i - 1];
    	}
    }
    q[0] = 0;
    for(i = 0; i < n; i++) {
    	if(q[i] < min) min = q[i];
    }
    for(i = 0; i < n; i++) {
    	q[i] += -min + 1;
    }
    for(i = 0; i < n; i++) {
    	b[i] = 0;
    }
    for(i = 0; i < n; i++) {
    	if(q[i] < 0 || q[i] > n)
    		no();
    	b[q[i] - 1]++;
    }
    for(i = 0; i < n; i++) {
    	if (b[i] != 1) no();
    }
    for(i = 0; i < n; i++) {
		printf("%d ", q[i]);
    }
    return 0;   
}

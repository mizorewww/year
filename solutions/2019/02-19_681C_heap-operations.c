/* Codeforces 681C - Heap Operations
 * https://codeforces.com/problemset/problem/681/C
 * rating: 1600 | tags: constructive algorithms, data structures, greedy
 * source: accepted submission #22090117 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

#include <string.h>

#define NMAX 1000010

#define OPER_LEN 20



const char 	*INSERT = "insert",

			*GETMIN = "getMin",

			*REMOVEMIN = "removeMin";



int m;

char records[NMAX][OPER_LEN];

int size, heap[NMAX];



void swap(int *a, int *b) {

	int tmp = *a;

	*a = *b;

	*b = tmp;

}



void lift(int c) {

	int p;

	while (c > 1) {

		p = c / 2;

		if (heap[p] <= heap[c])

			return;

		swap(heap + p, heap + c);

		c = p;

	}

}



void sift(int p) {

	int c;

	while (2 * p <= size) {

		c = 2 * p;

		if (c < size && heap[c + 1] < heap[c])

			c = c + 1;

		if (heap[p] <= heap[c])

			return;

		swap(heap + p, heap + c);

		p = c;

	}

}



void removeMin() {

	heap[1] = heap[size--];

	sift(1);

}



int getMin() {

	return heap[1];

}



void insert(int a) {

	heap[++size] = a;

	lift(size);

}



int main(void) {

	//freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

	

	int i, n, a;

	char oper[OPER_LEN];



	scanf("%d", &n);

	for (i = 0; i < n; ++i) {

		scanf("\n%s", oper);

		if (!strcmp(oper, INSERT)) {

			scanf("%d", &a);

			insert(a);

			sprintf(records[m++], "%s %d", oper, a);

		}

		else if (!strcmp(oper, REMOVEMIN)) {

			if (!size) {

				insert(0);

				sprintf(records[m++], "%s 0", INSERT);							

			}

			sprintf(records[m++], "%s", oper);			

			removeMin();

		}	

		else if (!strcmp(oper, GETMIN)) {

			scanf("%d", &a);

			if (!size || getMin() != a) {

				while (size > 0 && getMin() < a) {

					removeMin();

					sprintf(records[m++], REMOVEMIN);

				}

				if (!size || getMin() > a) {

					insert(a);

					sprintf(records[m++], "%s %d", INSERT, a);

				}

			}

			sprintf(records[m++], "%s %d", oper, a);

		}

	}

	

	printf("%d\n", m);

	for (i = 0; i < m; ++i) 

		puts(records[i]);



	return 0;

}

/* Codeforces 111C - Petya and Spiders
 * https://codeforces.com/problemset/problem/111/C
 * rating: 2100 | tags: bitmasks, dp, dsu
 * source: accepted submission #662584 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//THE GENERATOR
/*
#define MAXD 55

static int a[MAXD];
static int b[MAXD];
int N, M, D;

char Check ()
{
	memcpy(b,a,sizeof(a));
	int i, x, y;
	for (i = 0; i < D; i++)
	{
		if (a[i])
		{
			x = i / M;
			y = i % M;

			if (x > 0) b[i - M] = 1;
			if (x < (N-1)) b[i + M] = 1;
			if (y > 0) b[i - 1] = 1;
			if (y < (M-1)) b[i + 1] = 1;
		}
	}
	for (i = 0; i < D; i++)
	{
		if (!b[i]) return 0;
	}
	return 1;
}

int main ()
{
	for (N = 1; N <= 40; N++)
	{
		int used = 1;
		for (M = N; (N*M) <= 40; M++)
		{
			D = N * M;
			int i, j, k;
			while (1)
			{
				memset(a,0,sizeof(a));
				for (i = D-used; i < D; i++) a[i] = 1;
				char flag = 0;
				while (1)
				{
					if (Check())
					{
						flag = 1;
						break;
					}
					i = D-2;
					while (i >= 0)
					{
						if ((a[i] == 0) && (a[i+1] == 1)) break;
						i--;
					}
					if (i < 0) break;
					a[i] = 1;
					a[i+1] = 0;
					i = i+2;
					j = D-1;
					while (i < j)
					{
						k = a[i]; a[i] = a[j]; a[j] = k;
						i++; j--;
					}
				}
				if (flag) break;
				used++;
			}
			printf("if ((N == %d) && (M == %d)) printf(\"%%d\\n\",%d);\n",N,M,D-used);
		}
	}
	return 0;
}
*/
//THE PROGRAM

int main ()
{
	int N, M;
	scanf("%d %d",&N,&M);
	if (N > M)
	{
		int y = N; N = M; M = y;
	}
	if ((N == 1) && (M == 1)) printf("%d\n",0);
	if ((N == 1) && (M == 2)) printf("%d\n",1);
	if ((N == 1) && (M == 3)) printf("%d\n",2);
	if ((N == 1) && (M == 4)) printf("%d\n",2);
	if ((N == 1) && (M == 5)) printf("%d\n",3);
	if ((N == 1) && (M == 6)) printf("%d\n",4);
	if ((N == 1) && (M == 7)) printf("%d\n",4);
	if ((N == 1) && (M == 8)) printf("%d\n",5);
	if ((N == 1) && (M == 9)) printf("%d\n",6);
	if ((N == 1) && (M == 10)) printf("%d\n",6);
	if ((N == 1) && (M == 11)) printf("%d\n",7);
	if ((N == 1) && (M == 12)) printf("%d\n",8);
	if ((N == 1) && (M == 13)) printf("%d\n",8);
	if ((N == 1) && (M == 14)) printf("%d\n",9);
	if ((N == 1) && (M == 15)) printf("%d\n",10);
	if ((N == 1) && (M == 16)) printf("%d\n",10);
	if ((N == 1) && (M == 17)) printf("%d\n",11);
	if ((N == 1) && (M == 18)) printf("%d\n",12);
	if ((N == 1) && (M == 19)) printf("%d\n",12);
	if ((N == 1) && (M == 20)) printf("%d\n",13);
	if ((N == 1) && (M == 21)) printf("%d\n",14);
	if ((N == 1) && (M == 22)) printf("%d\n",14);
	if ((N == 1) && (M == 23)) printf("%d\n",15);
	if ((N == 1) && (M == 24)) printf("%d\n",16);
	if ((N == 1) && (M == 25)) printf("%d\n",16);
	if ((N == 1) && (M == 26)) printf("%d\n",17);
	if ((N == 1) && (M == 27)) printf("%d\n",18);
	if ((N == 1) && (M == 28)) printf("%d\n",18);
	if ((N == 1) && (M == 29)) printf("%d\n",19);
	if ((N == 1) && (M == 30)) printf("%d\n",20);
	if ((N == 1) && (M == 31)) printf("%d\n",20);
	if ((N == 1) && (M == 32)) printf("%d\n",21);
	if ((N == 1) && (M == 33)) printf("%d\n",22);
	if ((N == 1) && (M == 34)) printf("%d\n",22);
	if ((N == 1) && (M == 35)) printf("%d\n",23);
	if ((N == 1) && (M == 36)) printf("%d\n",24);
	if ((N == 1) && (M == 37)) printf("%d\n",24);
	if ((N == 1) && (M == 38)) printf("%d\n",25);
	if ((N == 1) && (M == 39)) printf("%d\n",26);
	if ((N == 1) && (M == 40)) printf("%d\n",26);
	if ((N == 2) && (M == 2)) printf("%d\n",2);
	if ((N == 2) && (M == 3)) printf("%d\n",4);
	if ((N == 2) && (M == 4)) printf("%d\n",5);
	if ((N == 2) && (M == 5)) printf("%d\n",7);
	if ((N == 2) && (M == 6)) printf("%d\n",8);
	if ((N == 2) && (M == 7)) printf("%d\n",10);
	if ((N == 2) && (M == 8)) printf("%d\n",11);
	if ((N == 2) && (M == 9)) printf("%d\n",13);
	if ((N == 2) && (M == 10)) printf("%d\n",14);
	if ((N == 2) && (M == 11)) printf("%d\n",16);
	if ((N == 2) && (M == 12)) printf("%d\n",17);
	if ((N == 2) && (M == 13)) printf("%d\n",19);
	if ((N == 2) && (M == 14)) printf("%d\n",20);
	if ((N == 2) && (M == 15)) printf("%d\n",22);
	if ((N == 2) && (M == 16)) printf("%d\n",23);
	if ((N == 2) && (M == 17)) printf("%d\n",25);
	if ((N == 2) && (M == 18)) printf("%d\n",26);
	if ((N == 2) && (M == 19)) printf("%d\n",28);
	if ((N == 2) && (M == 20)) printf("%d\n",29);
	if ((N == 3) && (M == 3)) printf("%d\n",6);
	if ((N == 3) && (M == 4)) printf("%d\n",8);
	if ((N == 3) && (M == 5)) printf("%d\n",11);
	if ((N == 3) && (M == 6)) printf("%d\n",13);
	if ((N == 3) && (M == 7)) printf("%d\n",15);
	if ((N == 3) && (M == 8)) printf("%d\n",17);
	if ((N == 3) && (M == 9)) printf("%d\n",20);
	if ((N == 3) && (M == 10)) printf("%d\n",22);
	if ((N == 3) && (M == 11)) printf("%d\n",24);
	if ((N == 3) && (M == 12)) printf("%d\n",26);
	if ((N == 3) && (M == 13)) printf("%d\n",29);
	if ((N == 4) && (M == 4)) printf("%d\n",12);
	if ((N == 4) && (M == 5)) printf("%d\n",14);
	if ((N == 4) && (M == 6)) printf("%d\n",17);
	if ((N == 4) && (M == 7)) printf("%d\n",21);
	if ((N == 4) && (M == 8)) printf("%d\n",24);
	if ((N == 4) && (M == 9)) printf("%d\n",26);
	if ((N == 4) && (M == 10)) printf("%d\n",30);
	if ((N == 5) && (M == 5)) printf("%d\n",18);
	if ((N == 5) && (M == 6)) printf("%d\n",22);
	if ((N == 5) && (M == 7)) printf("%d\n",26);
	if ((N == 5) && (M == 8)) printf("%d\n",29);
	if ((N == 6) && (M == 6)) printf("%d\n",26);
	return 0;
}

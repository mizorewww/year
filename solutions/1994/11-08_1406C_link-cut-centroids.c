/* Codeforces 1406C - Link Cut Centroids
 * https://codeforces.com/problemset/problem/1406/C
 * rating: 1700 | tags: constructive algorithms, dfs and similar, graphs, trees
 * source: accepted submission #92640655 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int X[100002];
int Y[100002];
int C[100002];
int W[100002];
int H[100002];
int V[200002];
int N[200002];
int c;
int sS[200002];
int sN[200002];
int sC;
void initial(int n)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		H[i] = -1;
	}
	c = 0;
}
void aE(int u, int v)
{
	N[c] = H[u];
	V[c] = v;
	H[u] = c;
	c++;
}
void DFSC()
{
	sS[0] = 0;
	sS[1] = 1;
	sN[1] = H[1];
	sC = 1;
	while (sC)
	{
		while (~sN[sC])
		{
			if (V[sN[sC]] - sS[sC - 1])
			{
				break;
			}
			else
			{
				sN[sC] = N[sN[sC]];
			}
		}
		if (~sN[sC])
		{
			sS[sC + 1] = V[sN[sC]];
			sN[sC + 1] = H[sS[sC + 1]];
			sN[sC] = N[sN[sC]];
			sC++;
		}
		else
		{
			C[sS[sC - 1]] += C[sS[sC]] + 1;
			sC--;
		}
	}
}
void DFSS()
{
	sS[0] = 0;
	sS[1] = 1;
	sN[1] = H[1];
	sC = 1;
	while (sC)
	{
		while (~sN[sC])
		{
			if (V[sN[sC]] - sS[sC - 1])
			{
				break;
			}
			else
			{
				sN[sC] = N[sN[sC]];
			}
		}
		if (~sN[sC])
		{
			sS[sC + 1] = V[sN[sC]];
			sN[sC + 1] = H[sS[sC + 1]];
			sN[sC] = N[sN[sC]];
			sC++;
		}
		else
		{
			if (C[sS[sC]] + 1 > W[sS[sC - 1]])
			{
				W[sS[sC - 1]] = C[sS[sC]] + 1;
			}
			sC--;
		}
	}
}
int main()
{
	int i;
	int T;
	int n;
	int min;
	int max;
	int aX, aY;
	int bX, bY;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		initial(n);
		for (i = 1; i <= n; i++)
		{
			C[i] = 0;
		}
		for (i = 1; i <= n; i++)
		{
			W[i] = 0;
		}
		for (i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &X[i], &Y[i]);
			aE(X[i], Y[i]);
			aE(Y[i], X[i]);
		}
		DFSC();
		DFSS();
		min = 1000000001;
		for (i = 1; i <= n; i++)
		{
			max = W[i];
			if (n - C[i] - 1 > max)
			{
				max = n - C[i] - 1;
			}
			if (max < min)
			{
				min = max;
				aX = i;
			}
		}
		aY = 0;
		for (i = 1; i <= n; i++)
		{
			max = W[i];
			if (n - C[i] - 1 > max)
			{
				max = n - C[i] - 1;
			}
			if (max == min)
			{
				if (i - aX)
				{
					aY =  i;
				}
			}
		}
		if (aY == 0)
		{
			aX = X[0];
			aY = Y[0];
			bX = X[0];
			bY = Y[0];
		}
		else
		{
			bX = aX;
			for (i = 0; i < n; i++)
			{
				if (X[i] == aX)
				{
					if (Y[i] - aY)
					{
						bY = aY;
						aY = Y[i];
						bX = Y[i];
						break;
					}
				}
				else if (Y[i] == aX)
				{
					if (X[i] - aY)
					{
						bY = aY;
						aY = X[i];
						bX = X[i];
						break;
					}
				}
			}
		}
		printf("%d %d\n", aX, aY);
		printf("%d %d\n", bX, bY);
	}
	return 0;
}

/* Codeforces 217C - Formurosa
 * https://codeforces.com/problemset/problem/217/C
 * rating: 2600 | tags: divide and conquer, dp, expression parsing
 * source: accepted submission #2029433 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define CANTRUE 0x1
#define CANFALSE 0x2
#define CANFLIP 0x4
#define cantrue(x) (x & CANTRUE)
#define canfalse(x) (x & CANFALSE)
#define canflip(x) (x & CANFLIP)
#define settrue(x) (x |= CANTRUE)
#define setfalse(x) (x |= CANFALSE)
#define setflip(x) (x |= CANFLIP)
#define zero (CANFALSE)
#define one (CANTRUE)
#define var (CANFLIP)

typedef unsigned char prop;

prop parse(void) {
	char c = getchar();
	prop x, y;
	prop me = 0;
	switch (c) {
		case '0':
			return zero;
		
		case '1':
			return one;

		case '?':
			return var;

		default:
			assert(c == '(');
			x = parse();
			c = getchar();
			y = parse();
			assert(getchar() == ')');
			switch(c) {
				case '&':
					if (canflip(x) && canflip(y)) {
						setflip(me);
						setfalse(me);
					};
					if ((canflip(x) && cantrue(y)) || (canflip(y) && cantrue(x)))
						setflip(me);
					if (canfalse(x) || canfalse(y))
						setfalse(me);
					if (cantrue(x) && cantrue(y))
						settrue(me);
					return me;

				case '|':
					if (canflip(x) && canflip(y)) {
						setflip(me);
						settrue(me);
					};
					if ((canflip(x) && canfalse(y)) || (canflip(y) && canfalse(x)))
						setflip(me);
					if (cantrue(x) || cantrue(y))
						settrue(me);
					if (canfalse(x) && canfalse(y))
						setfalse(me);
					return me;

				case '^':
					if (canflip(x) && canflip(y)) {
						settrue(me);
						setfalse(me);
					};
					if ((canflip(x) && (cantrue(y) || canfalse(y))) ||
							(canflip(y) && (cantrue(x) || canfalse(x))))
						setflip(me);
					if ((cantrue(x) && cantrue(y)) || (canfalse(x) && canfalse(y)))
						setfalse(me);
					if ((cantrue(x) && canfalse(y)) || (canfalse(x) && cantrue(y)))
						settrue(me);
					return me;

				default:
					assert(0);
			};
	};
};

int main(void) {
	prop x;
	scanf("%*d");
	while (getchar() != '\n');
   	x = parse();
	if (canflip(x))
		puts("YES");
	else
		puts("NO");
	return 0;
};

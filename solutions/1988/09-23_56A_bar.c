/* Codeforces 56A - Bar
 * https://codeforces.com/problemset/problem/56/A
 * rating: 1000 | tags: implementation
 * source: accepted submission #257667 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char str[102];
	int n,i,digit,age;
	long count ;

	scanf("%d",&n);
	count = 0;
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		digit = str[0]-'0';
		if(digit >=0 && digit <=9)
		{
			age = atoi(str);
			if(age < 18)
				count++;
		}
		else
		{
			if (strcmp(str,"ABSINTH") && strcmp(str,"BEER") && strcmp(str,"BRANDY") && strcmp(str,"CHAMPAGNE") && strcmp(str,"GIN") && strcmp(str,"RUM") && strcmp(str,"SAKE") && strcmp(str,"TEQUILA") && strcmp(str,"VODKA") && strcmp(str,"WHISKEY") && strcmp(str,"WINE"))
				;
			else 
				count++;
		}
	}

	printf("%ld\n",count);



	return 0;
}

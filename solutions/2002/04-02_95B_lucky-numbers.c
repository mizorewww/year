/* Codeforces 95B - Lucky Numbers
 * https://codeforces.com/problemset/problem/95/B
 * rating: 1800 | tags: dp, greedy
 * source: accepted submission #535177 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[1000000],s1[1000000];
int n;

int main() {
	int i,j,c,flag=0;
	scanf("%s",str);
	n=strlen(str);
	if (n%2==1) flag=1;
	for(i=j=c=0;i<n && i+abs(j)<=n && !flag && !c;i++) {
		if (str[i]<'4') c=1,s1[i]='4',j++;
		else if (str[i]=='4') s1[i]='4',j++;
		else if (str[i]<'7') s1[i]='7',j--,c=1;
		else if (str[i]=='7') s1[i]='7',j--;
		else break;
	}
	if (!flag && !c && i<n && i+abs(j)<=n) {
		for(--i;i>=0;i--) if (s1[i]=='4') break;
		if (i<0) flag=1; else {
			s1[i++]='7';
			for(c=j=0;c<i;c++) if (s1[c]=='4') j++; else j--;
			if (i+abs(j)>n) flag=1; else c=1;
		}
	}
	if (i+abs(j)>n) {
		for(;i>0 && (s1[i-1]=='7' || i+abs(j-2)>n);i--)
			if (s1[i-1]=='7') j++; else j--;
		if (i<=0) flag=1; else j--,s1[i-1]='7',j--,c=1;
	}
	if (c && i+abs(j)<=n) {
		if (j<0) {
			for(;j<0;i++,j++) s1[i]='4';
			for(j=0;j<(n-i)/2;j++) s1[i+j]='4';
			for(j=0;j<(n-i)/2;j++) s1[i+j+(n-i)/2]='7';
		} else {
			for(c=0;c<(n-i-j)/2;c++) s1[i+c]='4';
			for(i+=c;i<n;i++) s1[i]='7';
		}
	} else if (i<n || i+abs(j)>n) flag=1;
	if (flag) {
		for(i=0;i<n/2+1;i++) putchar('4');
		for(i=0;i<n/2+1;i++) putchar('7');
		puts("");
	} else puts(s1);
	return 0;
}

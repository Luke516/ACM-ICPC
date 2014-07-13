#include <stdio.h>
#include <string.h>

char c[150];

void find(int a, int b) {
	int i,last;
	for(i=a;;i--){
		if(c[i]!='.'){
			last=i;
			break;
		}
	}
	if (c[last ] == '(' && c[b + 1] == ')') {
		c[last ] = '.';
		c[b + 1] = '.';
		find(last , b + 1);
	}
	if (c[last ] == '[' && c[b + 1] == ']') {
		c[last ] = '.';
		c[b + 1] = '.';
		find(last , b + 1);
	}
	if (c[b + 1] == '(' && c[b + 2] == ')') {
		c[b + 1] = '.';
		c[b + 2] = '.';
		find(a, b + 2);
	}
	if (c[b + 1] == '[' && c[b + 2] == ']') {
		c[b + 1] = '.';
		c[b + 2] = '.';
		find(a, b + 2);
	}
	return;
}

int main() {
	int n, i, j;
	_Bool flag;
	scanf("%d", &n);
	gets(c);
	for (i = 0; i < n; i++) {
		gets(c);
		for (;;) {
			flag=0;
			for (j = 1; j < strlen(c); j++) {
				if (c[j - 1] == '(' && c[j] == ')') {
					flag=1;
					c[j - 1] = '.';
					c[j] = '.';
					find(j - 1, j);
				}
				if (c[j - 1] == '[' && c[j] == ']') {
					flag=1;
					c[j - 1] = '.';
					c[j] = '.';
					find(j - 1, j);
				}
			}
			if(flag==0)break;
		}
		if (strlen(c) == 0) {
			printf("Yes\n");
		}
		for (j = 0; j < strlen(c); j++) {
			if (c[j] != '.' && c[j] != ' ') {
				printf("No\n");
				break;
			} else if (j == strlen(c) - 1) {
				printf("Yes\n");
			}
		}
	}
	return 0;
}

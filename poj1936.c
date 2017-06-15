#include <stdio.h>
int main() {
	char a[100100],b[100100];
	int i,j;
	while(scanf("%s%s",a,b) != EOF) {
		for(i=j=0;b[j];j++)
			if(a[i] == b[j]) i++;
		printf("%s\n",a[i] ? "No":"Yes");
	}
	return 0;
}

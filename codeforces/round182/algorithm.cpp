#include <cstdio>

int main() {
	int i;
	for(i=0;i<=9;i++) printf("??%d>>%d??\n", i, i);
	printf("??>>?\n");
	for(i=0;i<9;i++) printf("%d?<>%d\n", i, i+1);
	printf("9?>>?0\n");
	printf("?<>1\n");
	printf(">>??\n");
	return 0;
}

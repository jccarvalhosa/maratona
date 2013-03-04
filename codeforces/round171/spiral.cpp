#include <cstdio>

int val(int a, int b) {
	int i=0, j=0, dir=0, k, num=0, ret=0;
	while(1) {
		if(a == 0 && b == 0) return 0;
		for(k=0;k<=num;k++) {
			if(dir == 0) i++;
			if(dir == 1) j++;
			if(dir == 2) i--;
			if(dir == 3) j--;
			if(i == a && j == b) return ret;
		}
		ret++;
		if(dir == 1 || dir == 3) num++;
		dir = (dir + 1) % 4;
	}
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", val(a, b));
	return 0;
}

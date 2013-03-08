#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 500000
#define MAXCOORD 1000000
#define MAXD 1000000

int main() {
	int i, x, y, z;
	srand(time(NULL));
	printf("%d\n", MAX);
	for(i=0;i<MAX;i++) {
		x = ((double)rand() / RAND_MAX - 0.5) * MAXCOORD;
		y = ((double)rand() / RAND_MAX - 0.5) * MAXCOORD;
		z = ((double)rand() / RAND_MAX - 0.5) * MAXCOORD;
		printf("%d %d %d\n", x, y, z);
	}
	printf("%d\n", MAX);
	for(i=0;i<MAX;i++) {
		x = ((double)rand() / RAND_MAX) * MAXD;
		y = ((double)rand() / RAND_MAX) * MAXD;
		printf("%d %d\n", x, y);
	}
	return 0;
}

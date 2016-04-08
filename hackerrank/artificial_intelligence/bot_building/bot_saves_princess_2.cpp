#include <stdio.h>
#include <string.h>
#include <math.h>
void nextMove(int n, int r, int c, char grid[101][101]){
	int pr, pc;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(grid[i][j]=='p') pr=i, pc=j;
	if(pr > r) printf("DOWN\n");
	else if(pr < r) printf("UP\n");
	else if(pc > c) printf("RIGHT\n");
	else if(pc < c) printf("LEFT\n");
}
int main(void) {

	int n, r, c;

	scanf("%d", &n);
	scanf("%d", &r);
	scanf("%d", &c);

	char grid[101][101];

	for(int i=0; i<n; i++) {
		scanf("%s[^\n]%*c", grid[i]);
	}

	nextMove(n, r, c, grid);
	return 0;
}

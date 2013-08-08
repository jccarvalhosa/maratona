#include <stdio.h>
#include <queue>

using namespace std;

typedef struct{
	int x;
	int y;
}Bit;


int main(){
	int dist[182][182], n, m, t, cont, i, j, d, x, y, trocou;
	char c[183];
	queue<Bit> q;
	Bit b;
	scanf("%d", &t);
	for(cont=0; cont<t;cont++){
		scanf("%d%d", &n, &m);
		for(i=0;i<n;i++) for(j=0;j<m;j++) dist[i][j] = -1;
		for(i=0;i<n;i++){
			scanf("%s", c);
			for(j=0;j<m;j++){
				if(c[j] == '1'){
					dist[i][j] = 0;
					b.x = i;
					b.y = j;
					q.push(b);
				}
			}
		}
		while(!q.empty()){
			x = q.front().x;
			y = q.front().y;
			if(x != n-1 && dist[x+1][y] == -1){
				dist[x+1][y] = dist[x][y] + 1;
				b.x = x+1;
				b.y = y;
				q.push(b);
			}
			if(x != 0 && dist[x-1][y] == -1){
				dist[x-1][y] = dist[x][y] + 1;
				b.x = x-1;
				b.y = y;
				q.push(b);
			}
			if(y != m-1 && dist[x][y+1] == -1){
				dist[x][y+1] = dist[x][y] + 1;
				b.x = x;
				b.y = y+1;
				q.push(b);
			}
			if(y != 0 && dist[x][y-1] == -1){
				dist[x][y-1] = dist[x][y] + 1;
				b.x = x;
				b.y = y-1;
				q.push(b);
			}
			q.pop();
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++) printf("%d ", dist[i][j]);
			printf("\n");
		}
	}
	return 0;
}


#include <stdio.h>
#include <queue>

using namespace std;

typedef struct{
	int x;
	int y;
	int d;
}Bit;

int main(){
	int map[182][182]; 
	int dist[182][182], n, m, t, cont, i, j, d;
	char c[183];
	queue<Bit> q;
	Bit b, primeiro;
	scanf("%d", &t);
	for(cont=0; cont<t;cont++){
		scanf("%d%d", &n, &m);
		for(i=0;i<n;i++){
			scanf("%s", c);
			for(j=0;j<m;j++){
				if(c[j] == '0') map[i][j] = 0;
				if(c[j] == '1') map[i][j] = 1;
			}
		}
		//para cada bit, um bfs.
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(map[i][j] == 1)	dist[i][j] = 0;
			else{
				d=0;
				b.x = i;
				b.y = j;
				b.d = 0;
				q.push(b);
				while(!q.empty()){
					primeiro = q.front();
					if(primeiro.x < n){
						if(map[primeiro.x + 1][primeiro.y] == 0){
							b.x = primeiro.x + 1;
							b.y = primeiro.y;
							b.d = primeiro.d + 1;
							q.push(b);
						}
						else{
							dist[i][j] = primeiro.d + 1;
							break;
						}
					}
					if(primeiro.y < m){
						if(map[primeiro.x][primeiro.y + 1] == 0){
							b.x = primeiro.x;
							b.y = primeiro.y + 1;
							b.d = primeiro.d + 1;
							q.push(b);
						}
						else{
							dist[i][j] = primeiro.d + 1;
							break;
						}
					}
					q.pop();
				}
				while(!q.empty()) q.pop();
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++) printf("%d ", dist[i][j]);
			printf("\n");
		}
	}
	return 0;
}



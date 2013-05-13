#include <stdio.h>
#include <queue>
#include <stdlib.h>

using namespace std;

typedef struct{
	int x;
	int y;
}Coord;

int main(){
	int n, m, i, j, num[10][10], dist[10][10], cor[10][10], dmin=1000;
	queue<Coord> q;
	Coord primeiro, outro;
	scanf("%d%d", &n, &m);
	for(i=0;i<n;i++) for(j=0;j<m;j++){
		cor[i][j] = 0;
		dist[i][j] = 0;
		scanf("%d", &num[i][j]);
		if(num[i][j] == 3){
			primeiro.x = i;
			primeiro.y = j;
			q.push(primeiro);
			cor[i][j] = 1;
		}
	}
	while(!q.empty()){
		primeiro = q.front();
		for(i=-1;i<=1;i++) if(!cor[primeiro.x + i][primeiro.y] && primeiro.x + i >= 0 && primeiro.x + i < n && num[primeiro.x + i][primeiro.y] != 2){
			outro.x = primeiro.x + i;
			outro.y = primeiro.y;
			q.push(outro);
			cor[outro.x][outro.y] = 1;
			dist[outro.x][outro.y] = dist[primeiro.x][primeiro.y] + 1;
			if(num[outro.x][outro.y] == 0) dmin = dmin < dist[outro.x][outro.y] ? dmin : dist[outro.x][outro.y];
		}
		for(j=-1;j<=1;j++) if(!cor[primeiro.x][primeiro.y + j] && primeiro.y + j >= 0 && primeiro.y + j < m && num[primeiro.x][primeiro.y + j] != 2){
			outro.x = primeiro.x;
			outro.y = primeiro.y + j;
			q.push(outro);
			cor[outro.x][outro.y] = 1;
			dist[outro.x][outro.y] = dist[primeiro.x][primeiro.y] + 1;
			if(num[outro.x][outro.y] == 0) dmin = dmin < dist[outro.x][outro.y] ? dmin : dist[outro.x][outro.y];
		}
		q.pop();
	}
	printf("%d\n", dmin);
	return 0;
}


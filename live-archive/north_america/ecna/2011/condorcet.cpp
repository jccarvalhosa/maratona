#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int ind[33333][555];
int t=1, b, c;

int cmp(int x, int y) {
	int sx=0, sy=0;
	for(int i=0;i<b;i++) {
		if(ind[x][i] > ind[y][i]) sy++;
		else sx++;
	}
	if(sx > sy) return 1;
	if(sy > sx) return -1;
	return 0;
}

int valid(int x) {
	for(int i=0;i<c;i++) if(c!=x && cmp(x, i) != 1) return 0;
	return 1;
}

int main() {
	while(1) { 
		cin>>b>>c;
		if(b==0) return 0;
		for(int i=0;i<b;i++) for(int j=0;j<c;j++) {
			int x;
			cin>>x;
			ind[x][i] = j;
		}
		queue<int> q;
		for(int i=0;i<c;i++) q.push(i);
		while(q.size() > 1) {
			int x = q.front();
			q.pop();
			int y = q.front();
			q.pop();
			int v = cmp(x, y);
			if(v == 1) q.push(x);
			if(v == -1) q.push(y);
		}
		printf("Case %d: ", t++);
		string error = "No Condorcet winner";
		if(q.empty()) cout<<error<<endl;
		else {
			int x = q.front();
			if(valid(x)) cout<<x<<endl;
			else cout<<error<<endl;
		}
	}
}

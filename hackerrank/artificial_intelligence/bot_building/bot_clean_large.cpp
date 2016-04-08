#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <sstream>
using namespace std;
typedef pair<int, int> pii;

int dp[20][1<<20], dist[20][20];
map<int, pii> id;

string dir(int posr, int posc, int i, int j) {
	if(i > posr) return "DOWN";
	if(i < posr) return "UP";
	if(j > posc) return "RIGHT";
	if(j < posc) return "LEFT";
	return "";
}

void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
	if(board[posr][posc] == 'd') {
		cout<<"CLEAN";
		return;
	}

	ifstream myfile ("example.txt");
	if (myfile.is_open()) {
		string line;
		getline (myfile,line);
		istringstream iss(line);
		int r, c;
		iss>>r>>c;
		myfile.close();
		if(board[r][c] == 'd') {
			cout << dir(posr, posc, r, c);
			return;
		}
	}

	id[0] = pii(posr, posc);
	int n = 1;
	for(int d=1;d<=dimh+dimw;d++) { 
		for(int i=0;i<dimh;i++) for(int j=0;j<dimw;j++) if(abs(i-posr) + abs(j-posc) == d) {
			if(n == 20) break;
			if(board[i][j] == 'd') id[n++] = pii(i, j);
		}
		if(n == 20) break;        
	}

	for(int i=0;i<n;i++) for(int j=0;j<n;j++) 
		dist[i][j] = abs(id[i].first - id[j].first) + abs(id[i].second - id[j].second);

	for(int i=0;i<n;i++) for(int j=0;j<1<<n;j++) dp[i][j] = 1e9;
	for(int i=0;i<n;i++) dp[i][1<<i] = 0;
	for(int vis=1;vis<1<<n;vis++) for(int i=0;i<n;i++) if(vis & (1<<i)) {
		if(vis == (1<<i)) {
			dp[i][vis]=0;
			continue;
		}
		for(int j=0;j<n;j++) if(i != j && (vis & (1<<j))) {
			dp[i][vis] = min(dp[i][vis], dist[i][j] + dp[j][vis - (1<<i)]);
		}
	}
	for(int i=1;i<n;i++) if(dp[0][(1<<n)-1] == dist[0][i] + dp[i][(1<<n) - 2]) {
		cout << dir(posr, posc, id[i].first, id[i].second);
		ofstream myfile;
		myfile.open ("example.txt");
		myfile << id[i].first << " " << id[i].second << endl;
		myfile.close();
		return;
	}
}
int main(void) {
	int pos[2];
	int dim[2];
	vector <string> board;
	cin>>pos[0]>>pos[1];
	cin>>dim[0]>>dim[1];
	for(int i=0;i<dim[0];i++) {
		string s;cin >> s;
		board.push_back(s);
	}
	next_move(pos[0], pos[1], dim[0], dim[1], board);
	return 0;
}

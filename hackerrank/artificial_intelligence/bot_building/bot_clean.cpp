#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
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

void next_move(int posr, int posc, vector <string> board) {
	if(board[posr][posc] == 'd') {
		cout<<"CLEAN";
		return;
	}
	int n = 1;
	id[0] = pii(posr, posc);
	for(int i=0;i<board.size();i++) for(int j=0;j<board[i].size();j++) {
		if(board[i][j] == 'd') id[n++] = pii(i, j);
	}

	if(n > 20) {
		int dist = 1e9;
		string ret;
		for(int i=0;i<board.size();i++) for(int j=0;j<board[i].size();j++) {
			int d = abs(i-posr) + abs(j-posc);
			if(board[posr][i] == 'd' && dist>d) {
				dist = d;
				ret = dir(posr, posc, i, j);
			}
		}
		cout << ret;
		return;
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
		return;
	}
}
int main(void) {
	int pos[2];
	vector <string> board;
	cin>>pos[0]>>pos[1];
	for(int i=0;i<5;i++) {
		string s;cin >> s;
		board.push_back(s);
	}
	next_move(pos[0], pos[1], board);
	return 0;
}

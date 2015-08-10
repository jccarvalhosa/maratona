#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int M = 1e9+7;
const int H = 2e5+1;
const int N = 2e3+2;

ll fat[H], inv[H];
ll dp[N], ways[N][N];

ll exp(ll a, int e) {
	if(!e) return 1;
	if(e&1) return (a*exp(a, e-1))%M;
	return exp((a*a)%M, e/2);
}

int main() {
	int h, w, n;
	cin>>h>>w>>n;	
	fat[0] = inv[0] = 1;
	for(int i=1;i<=h+w;i++) fat[i] = (fat[i-1] * i) % M;
	for(int i=1;i<=h+w;i++) inv[i] = exp(fat[i], M-2);
	vector<pii> v;
	v.push_back(pii(1, 1));
	v.push_back(pii(h, w));
	for(int i=0;i<n;i++) {
		int x, y;
		cin>>x>>y;
		v.push_back(pii(x, y));
	}
	sort(v.begin(), v.end());
	n += 2;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			int dx = v[j].first - v[i].first;
			int dy = v[j].second - v[i].second;
			if(dx < 0 || dy < 0)
				ways[i][j] = 0;
			else
				ways[i][j] = (fat[dx+dy]*inv[dx]%M)*inv[dy]%M;
		}
	}
	dp[0] = 1;
	for(int i=1;i<n;i++) {
		dp[i] = ways[0][i];
		for(int j=1;j<i;j++) {
			dp[i] = (((dp[i] - dp[j] * ways[j][i]) % M) + M) % M;
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}

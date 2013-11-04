#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N=10001;
int n, v[N];
struct stream {int i, f, p; };
stream s[N];
vector<stream> vi[N];

int main() {
	cin>>n;
	int d, nt=0;
	for(int i=0;i<n;i++) {
		cin>>s[i].i>>d>>s[i].p;
		s[i].f = s[i].i+d;
		v[nt++] = s[i].i;
		v[nt++] = s[i].f;
	}
	sort(v, v+nt);
	nt = unique(v, v+nt) - v;
	map<int, int> id;
	for(int i=0;i<nt;i++) id[v[i]]=i;
	for(int i=0;i<n;i++) {
		s[i].i = id[s[i].i];
		s[i].f = id[s[i].f];
		vi[s[i].i].push_back(s[i]);
	}
	vector<vector<int> > dp(nt);
	for(int i=0;i<nt;i++) dp[i] = vector<int>(nt-i, 0);
	for(int tam=2;tam<=nt;tam++) for(int i=0;i<nt;i++) {
		int f = i+tam-1;
		if(f>=nt) break;
		dp[i][f-i] = dp[i+1][f-i-1];
		int sum=0;
		for(int j=0;j<vi[i].size();j++) {
			if(vi[i][j].f == f) sum += vi[i][j].p; 
			if(vi[i][j].f < f) dp[i][f-i] = max(dp[i][f-i], dp[i][vi[i][j].f-i] + dp[vi[i][j].f][f-vi[i][j].f]);
		}
		dp[i][f-i] += sum;
	}
	cout << dp[0][nt-1] << endl;
	return 0;
}

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

string w[222];
long double dp[1111][222], p[1111][33];
int valid[222][222], c[1111][222];

int main() {
	int i, j, l, d, k, t, n;
	ifstream in("decoding.in");
	ofstream out("decoding.out");
	in >> d >> k >> t;
	for(i=0; i<d; i++) in >> w[i];
	for(i=0; i<d; i++) for(j=0; j<d; j++) if(w[i].substr(1, k-1)==w[j].substr(0, k-1)) valid[i][j]=1;
	in >> n;
	for(i=0; i<n; i++) for(j=0; j<t; j++) in >> p[i][j];
	for(i=0; i<n; i++) for(j=0; j<d; j++) dp[i][j]=0.0;
	for(i=0; i<d; i++) c[n-1][i]=-1;
	for(i=0; i<d; i++) dp[k-1][i]=1.0;
	for(i=0; i<d; i++) for(j=0; j<k; j++) dp[k-1][i]*=p[j][w[i][j]-'a'];
	for(i=0; i<d; i++) c[k-1][i]=i;
	for(i=k; i<n; i++) for(j=0; j<d; j++) for(l=0; l<d; l++) if(valid[l][j] && dp[i][j]<dp[i-1][l]*p[i][w[j][k-1]-'a']) {
		dp[i][j]=dp[i-1][l]*p[i][w[j][k-1]-'a'];
		c[i][j]=l;
	}
	long double _max=0.0;
	int id=-1;
	for(i=0; i<d; i++) if(dp[n-1][i]>_max) _max=dp[n-1][i], id=i;
	if(id==-1 || c[n-1][id]==-1) out << "---" << endl;
	else {
		vector<int> sol;
		for(i=n-1; i>=k-1; i--) {
			sol.push_back(id);
			id=c[i][id];
		}
		reverse(sol.begin(), sol.end());
		out << w[sol[0]];
		for(i=1; i<sol.size(); i++) out << w[sol[i]][k-1];
		out << endl;
	}
	return 0;
}

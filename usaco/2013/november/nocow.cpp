#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ifstream in("nocow.in");
ofstream out("nocow.out");
vector<string> v[33], oldv[33];
vector<int> vv[111];
int m, ans[33], nv;
ll p[33];

void go(int n, int k) {
	if(n==m) {
		out<<v[0][ans[0]];
		for(int i=1;i<m;i++) out<<" "<<v[i][ans[i]];
		out<<endl;
		return;
	}
	ll sum=0;
	for(int c=0;c<v[n].size();c++) {
		int cont=0;
		for(int i=0;i<nv;i++) if(vv[i][n] == c) cont++;
		ll nsum = sum + p[n+1]-cont;
		if(nsum > k) {
			ans[n]=c;
			for(int i=0;i<nv;i++) if(vv[i][n] != c) swap(vv[i--], vv[--nv]);
			go(n+1, k-sum);
			return;
		}
		sum = nsum;
	}
}

int main() {
	int n, k;
	in>>n>>k;
	for(int i=0;i<n;i++) {
		string s;
		in>>s; //Farmer
		in>>s; //John
		in>>s; //has
		in>>s; //no
		int j;
		for(j=0;;j++) {
			in>>s;
			if(s=="cow.") break;
			v[j].push_back(s);
		}
		m=j;
	}
	for(int i=0;i<m;i++) oldv[i] = v[i];
	for(int i=0;i<m;i++) {
		sort(v[i].begin(), v[i].end());
		v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
	}
	p[m]=1;
	for(int i=m-1;i>=0;i--) p[i] = p[i+1]*v[i].size();
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) vv[j].push_back(lower_bound(v[i].begin(), v[i].end(), oldv[i][j]) - v[i].begin());
	nv = n;
	go(0, k-1);
	return 0;
}

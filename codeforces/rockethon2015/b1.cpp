#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

int get(vector<int> v) {
	int ans = 0;
	for(int i=0;i<v.size();i++) {
		int m = v[i];
		for(int j=i;j<v.size();j++) {
			m = min(m, v[j]);
			ans += m;
		}
	}
	return ans;
}

int main() {
	int n;
	ll m;
	cin>>n>>m;
	vector<int> v;
	for(int i=0;i<n;i++) v.push_back(i);
	reverse(v.begin(), v.end());
	int fp = get(v);
	reverse(v.begin(), v.end());
	do {
		int aux = get(v);
		if(aux == fp) {
			if(m==1) break;
			m--;
		}
	} while(next_permutation(v.begin(), v.end()));
	for(int i=0;i<v.size();i++) {
		if(i) cout << " ";
		cout << v[i]+1;
	}
	cout << endl;
	return 0;
}

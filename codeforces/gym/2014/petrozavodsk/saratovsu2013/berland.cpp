#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

int fit(pii p, vector<pii>&v) {
	if(v.empty()) return 1;
	return v.back().first <= p.first && v.back().second >= p.second;
}

void transfer(vector<pii>&orig, vector<pii>&dest) {
	dest.insert(dest.end(), orig.begin(), orig.end());
	orig.clear();
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<pii> v, v1, v2, v3;
		while(n--) {
			int a, b;
			scanf("%d%d", &a, &b);
			if(a>b) swap(a, b);
			v.push_back(pii(a-b, a));
		}
		sort(v.begin(), v.end());
		int ok=1;
		for(int i=0;i<v.size();i++) {
			int a = v[i].second;
			int b = -v[i].first + v[i].second;
			pii p(a, b);
			if(fit(p, v1) && fit(p, v2)) {
				if(fit(p, v3)) v3.push_back(p);
				else {
					v2.push_back(p);
					transfer(v3, v1);
				}
			} 
			else if(fit(p, v1)) {
				v1.push_back(p);
				transfer(v3, v2);
			}
			else if(fit(p, v2)) {
				v2.push_back(p);
				transfer(v3, v1);
			}
			else {
				ok=0;
				break;
			}
		}
		transfer(v3, v1);
		if(!v1.empty() && !v2.empty() && (v1.back().second < v2.back().first || v2.back().second < v1.back().first)) ok=0;
		if(!ok) cout<<"no"<<endl;
		else {
			cout<<"yes"<<endl;
			for(int i=0;i<v1.size();i++) cout<<v1[i].first<<" "<<v1[i].second<<endl;
			for(int i=v2.size()-1;i>=0;i--) cout<<v2[i].second<<" "<<v2[i].first<<endl;
		}
	}
	return 0;
}

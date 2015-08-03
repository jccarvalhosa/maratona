#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<double, ll> pii;

int n;
vector<int> v;

int inv() {
	int ans=0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(v[j] < v[i]) ans++;
	return ans;
}

pii calc(int k) {
	if(k==0) {
		return pii(inv(), 1);
	}
	ll cnt=0;
	double avg=0;
	for(int i=0;i<n;i++) for(int j=i;j<n;j++) {
		for(int k=0;;k++) {
			int pi = i+k;
			int pj = j-k;
			if(pj <= pi) break;
			swap(v[pi], v[pj]);
		}
		pii aux = calc(k-1);
		avg = (avg * cnt + aux.first * aux.second) / (cnt + aux.second);
		cnt += aux.second;
		for(int k=0;;k++) {
			int pi = i+k;
			int pj = j-k;
			if(pj <= pi) break;
			swap(v[pi], v[pj]);
		}
	}
	return pii(avg, cnt);
}

int main() {
	int k;
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		int p;
		cin>>p;
		v.push_back(p);
	}
	printf("%.12lf\n", calc(k).first);
	return 0;
}

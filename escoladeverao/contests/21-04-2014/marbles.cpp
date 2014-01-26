#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll v[22];
int n[] = {2, 3, 4, 6, 8, 9};
ll pot[22][22];

int go(int pos, ll s1, ll s2, ll p1, ll p2) {
	if(pos==6) {
		if(p1 != p2) return 0;
		if(max(s1,s2) - min(s1,s2) <= v[1]) return 1;
		return 0;
	}
	for(int i=0;i<=v[n[pos]];i++) {
		if(2*i==v[n[pos]] && go(pos+1, s1, s2, p1, p2)) return 1;
		if(2*i>v[n[pos]] && go(pos+1, s1+2*i-v[n[pos]], s2, p1*pot[n[pos]][2*i-v[n[pos]]], p2)) return 1;
		if(2*i<v[n[pos]] && go(pos+1, s1, s2+v[n[pos]]-2*i, p1, p2*pot[n[pos]][v[n[pos]]-2*i])) return 1;
	}
	return 0;
}

int solve() {
	if(v[0]==1) return 0;
	if(v[0]>1) return 1;
	if(v[5]&1) return 0;
	if(v[7]&1) return 0;
	for(int i=2;i<=9;i++) {
		if(v[i] > 4) {
			if(v[i]&1) v[i]=5;
			else v[i]=6;
		}
	}
	if(go(0, 0, 0, 1, 1)) return 1;
	return 0;
}

int main() {
	for(int i=1;i<=9;i++) {
		pot[i][0]=1;
		for(int j=1;j<=10;j++) pot[i][j] = i*pot[i][j-1];
	}
	int T;
	cin>>T;
	while(T--) {
		for(int i=0;i<=9;i++) cin>>v[i];
		cout << (solve()?"TAK":"NIE") << endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int N=1e6+1;
string s[N];

bool cmp(const string &a, const string &b) { return a.size() > b.size(); }
	
int n;

int go(int h, int og, int os, int m) {
	int ng=0, ns=0, nf=0;
	for(int i=0;i<n && s[i].size() > h;i++) {
		if(s[i].size() == h+1) nf++;
		if(s[i][h] == 'S') ns++;
		if(s[i][h] == 'G') ng++;
	}
	ns = min(ns, os + nf);
	ng = min(ng, og + nf);
	int nm = min(m + nf, ng + ns);
	if(h == 0) return nm;
	return go(h-1, ng, ns, nm);
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	sort(s, s+n, cmp);
	cout << go(s[0].size()-1, 0, 0, 0) << endl;
	return 0;
}

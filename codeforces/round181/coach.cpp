#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int g[48], f[48], l[48], next[48], size[48], valid[48];
vector<int> v1, v2, v3;

int main() {
	int n, m, i, j, a, b, s1, s2, s3;
	cin>>n>>m;
	for(i=0;i<n;i++) {
		g[i] = i;
		f[i] = l[i] = i;
		size[i] = valid[i] = 1;
	}
	for(i=0;i<m;i++) {
		cin>>a>>b; a--; b--;
		if(size[g[a]] < size[g[b]]) swap(a, b);
		if(g[a] != g[b]) {
			size[g[a]] += size[g[b]];
			valid[g[b]] = 0;
			for(j = f[b]; ; j = next[j]) {
				g[j] = g[a];
				if(j == l[b]) break;
			}
			next[l[a]] = f[b];
			l[a] = l[b];
		}
	}
	for(i=0;i<n;i++) if(valid[i] && size[i] > 3) break;
	if(i != n) cout<<-1<<endl;
	else {
		for(i=0;i<n;i++) if(valid[i]) {
			if(size[i] == 1) v1.push_back(i);
			if(size[i] == 2) v2.push_back(i);
			if(size[i] == 3) v3.push_back(i);
		}
		s1 = v1.size();
		s2 = v2.size();
		s3 = v3.size();
		if(s2 > s1) cout<<-1<<endl;
		else {
			a = s1 - s2;
			if(a % 3 != 0) cout<<-1<<endl;
			else {
				for(i=0;i<s3;i++) {
					a = v3[i];
					b = f[a];
					cout << b+1 << " " << next[b]+1 << " " << next[next[b]]+1 << endl;
				}
				j = 0;
				for(i=0;i<s2;i++) {
					a = v2[i];
					b = v1[j++];
					cout << f[a]+1 << " " << next[f[a]]+1 << " " << f[b]+1 << endl;
				}
				for(; j < s1; j+= 3) {
					cout << f[v1[j]]+1 << " " << f[v1[j+1]]+1 << " " << f[v1[j+2]]+1 << endl;
				}
			}
		}
	}
	return 0;
}

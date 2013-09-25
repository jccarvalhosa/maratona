#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;
typedef pair<int, int> pii;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int c[22], n, m, h, w;
pii p[11], vx[11], vy[11];

void print() {
	int tab[22][22] = {0};
	for(int i=0;i<n;i++) tab[p[i].first][p[i].second]++;
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) printf("%d", tab[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {
	int T=1;
	while(1) {
		cin>>h>>w;
		if(h==0) return 0;
		cin>>n;
		for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
		//print();
		
		for(int i=0;i<n;i++) vx[i] = pii(p[i].first, i); 
		sort(vx, vx+n);
		for(int i=0;i<n;i++) vy[i] = pii(p[i].second, i); 
		sort(vy, vy+n);

		while(1) {
			string s;
			cin>>s;
			if(s == "done") break;
			int v;
			cin>>v;
		
			int my=0;
			for(int i=0;i<h;i++) c[i]=0;
			for(int i=0;i<n;i++) c[p[i].first]++;
			for(int i=0;i<h;i++) my = max(my, c[i]);
			
			int mx=0;
			for(int i=0;i<w;i++) c[i]=0;
			for(int i=0;i<n;i++) c[p[i].second]++;
			for(int i=0;i<w;i++) mx = max(mx, c[i]);

			//cout<<mx<<" "<<my<<endl;

			if(s == "left") {
				for(int i=0;i<h;i++) c[i]=0;
				v = max(w-v-1, my-1);
				for(int i=n-1;i>=0;i--) {
					int pos = vy[i].second;
					int x = p[pos].first;
					if(p[pos].second >= v - c[x]) p[pos].second = v - c[x]++;
				}
			}
			
			if(s == "right") {
				for(int i=0;i<h;i++) c[i]=0;
				v = min(v, w-my);
				for(int i=0;i<n;i++) {
					int pos = vy[i].second;
					int x = p[pos].first;
					if(p[pos].second <= v + c[x]) p[pos].second = v + c[x]++;
				}
			}
			
			if(s == "down") {
				for(int i=0;i<w;i++) c[i]=0;
				v = min(v, h-mx);
				for(int i=0;i<n;i++) {
					int pos = vx[i].second;
					int y = p[pos].second;
					if(p[pos].first <= v + c[y]) p[pos].first = v + c[y]++;
				}
			}
			
			if(s == "up") {
				for(int i=0;i<w;i++) c[i]=0;
				v = max(h-v-1, mx-1);
				for(int i=n-1;i>=0;i--) {
					int pos = vx[i].second;
					int y = p[pos].second;
					if(p[pos].first >= v - c[y]) p[pos].first = v - c[y]++;
				}
			}

			//print();
		}
		cout<<"Data set "<<T++<<" ends with boxes at locations";
		int tab[22][22] = {0};
		for(int i=0;i<n;i++) tab[p[i].first][p[i].second]++;
		for(int i=0;i<h;i++) for(int j=0;j<w;j++) if(tab[i][j]) cout<<" ("<<i<<","<<j<<")";
		cout<<".\n";
	}
}

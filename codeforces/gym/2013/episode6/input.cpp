#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct tile { int x, y, X, Y; };

bool overlap(tile a, tile b) {
	if(a.X <= b.x) return false;
	if(b.X <= a.x) return false;
	if(a.Y <= b.y) return false;
	if(b.Y <= a.y) return false;
	return true;
}
			
vector<tile> v;
int l, w, n;

string solve() {
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(overlap(v[i], v[j])) return "NONDISJOINT";
	for(int i=0;i<n;i++) if(v[i].x < 0 || v[i].X > w || v[i].y < 0 || v[i].Y > l) return "NONCONTAINED";
	int area = l*w, sum=0;
	for(int i=0;i<n;i++) sum += (v[i].X-v[i].x)*(v[i].Y-v[i].y);
	if(sum != area) return "NONCOVERING";
	return "OK";
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>w>>l>>n;
		v.resize(n);
		for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y>>v[i].X>>v[i].Y;
		cout << solve() << endl;
	}
	return 0;
}

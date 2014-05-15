#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> vv;

const int N=50;
int cont[N+1];

int ans[51] = {0, 1, 2, 2, 4, 5, 10, 10, 18, 20, 36, 36, 62, 65, 110, 110, 180, 185, 300, 300, 474, 481, 752, 752, 1154, 1165, 1770, 1770, 2650, 2665, 3956, 3956, 5800, 5822, 8470, 8470, 12200, 12230, 17490, 17490, 24800, 24842, 35002, 35002, 48954, 49010, 68150, 68150, 94158, 94235, 129512};

set<vv> vis;

void go(vv v, int n) {
	if(vis.count(v)) return;
	vis.insert(v);
	cont[n]++;
	int m = v.size();
	if(n != N) {
		for(int i=0;i<m;i++) if(i == 0 || v[i] < v[i-1]) {
			if(i&1) {
				if(v[i]%2 != n%2) {
					vv u = v;
					u[i]++;
					go(u, n+1);
				}
			}
			else {
				if(v[i]%2 == n%2) {
					vv u = v;
					u[i]++;
					go(u, n+1);
				}
			}
		}
		if(m%2 == n%2) {
			v.push_back(1);
			go(v, n+1);
		}
	}
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	vector<int> v(1, 1);
	//go(v, 1);
	//cout << "int ans[51] = {"; for(int i=0;i<=50;i++) { if(i) cout << ", "; cout << cont[i]; } cout << "}; " << endl;
	int n;
	cin>>n;
	cout << ans[n] << endl;
	return 0;
}

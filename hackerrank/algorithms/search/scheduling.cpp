#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;

const int M=100000;
int t[M+1];

int query(int x) {int ret=-x;for(;x<=M;x+=x&-x)ret+=t[x];return ret;}
void add(int x, int v) {for(;x;x-=x&-x) t[x]+=v;}

int main() {
	int T;
	cin>>T;
	set<int> s;
	for(int i=1;i<=M;i++) s.insert(i);
	for(int n=1;n<=T;n++) {
		int x, m;
		cin>>x>>m;
		add(M, m);
		add(x-1, -m);
		set<int>::iterator it = s.lower_bound(x);
		int vx = query(*it);
		if(it != s.begin()) {
			it--;
			while(query(*it) <= vx) {
				if(it == s.begin()) {
					s.erase(it);
					break;
				}
				else s.erase(it--);
			}
		}
		cout << max(0, query(*s.begin())) << endl;
	}
	return 0;
}

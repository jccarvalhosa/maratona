#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

const int N=1e6+10;
int n, v[N], t[N], pos[N];

void add(int p, int k) { for(;p<=n;p+=p&-p) t[p] += k; }
int sum(int p) { int ret=0; for(;p;p-=p&-p) ret += t[p]; return ret; } 

void update(int p, int v) { for(;p<=n;p+=p&-p) pos[p] = max(pos[p], v); }
int query(int p) { int ret=0; for(;p;p-=p&-p) ret = max(ret, pos[p]); return ret;}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d", &v[i]);

	long long ans=0;
	set<pii> s;
	for(int i=1;i<=n;i++) {
		ans++;
		while(!s.empty()) {
			set<pii>::iterator it = --s.end();
			if((*it).first > v[i]) {
				add((*it).second, -1);
				s.erase(*it);
			}
			else {
				break;
			}
		}
		int start = query(n - v[i] + 1);
		ans += sum(n) - sum(start);
		update(n - v[i] + 1, i);
		add(i, 1);
		s.insert(pii(v[i], i));
	}
	cout << ans << endl;
	return 0;
}

#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int N, t[111111];

void add(int a, int v) { for(int i=a;i<=N;i+=i&-i) t[i]+=v; }
int sum(int a) {
	int ret=0;
	for(int i=a;i;i-=i&-i) ret+=t[i];
	return ret;
}
int sum(int a, int b) { return sum(b) - sum(a-1); }

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, q;
		cin>>n>>q;
		N=n+1;
		string s;
		cin>>s;
		s = "." + s + ".";
		set<int> up;
		for(int i=0;i<=N;i++) {
			up.insert(i);
			t[i]=0;
		}
		for(int i=1;i<=n;i++) if(s[i-1]=='>' && s[i]=='<') add(i, 1);
		while(q--) {
			int c;
			cin>>c;
			if(c==3) {
				int a, b;
				cin>>a>>b;
				int ans = sum(a, b);
				set<int>::iterator it = up.lower_bound(a);
				if(*it <= b && s[*it] == '<') {
					it--;
					if(s[*it]=='>') ans--;
				}
				cout<<ans<<endl;
			}
			else {
				int x;
				cin>>x;
				set<int>::iterator it = up.upper_bound(x);
				int r = *it;
				it--;
				if(*it == x) it--;
				int l = *it;
				if(c==1) {
					int delta;
					if(up.count(x)) {
						up.erase(x);
						delta=-1;
					} else {
						up.insert(x);
						delta=1;
					}
					if(s[l]=='>' && s[x]=='<') add(x, delta);
					if(s[x]=='>' && s[r]=='<') add(r, delta);
					if(s[l]=='>' && s[r]=='<') add(r, -delta);
				}
				if(c==2) {
					int isup = up.count(x);
					if(isup) {
						if(s[l]=='>' && s[x]=='<') add(x, -1);
						if(s[x]=='>' && s[r]=='<') add(r, -1);
					}
					s[x] = (s[x]=='<' ? '>' : '<');
					if(isup) {
						if(s[l]=='>' && s[x]=='<') add(x, 1);
						if(s[x]=='>' && s[r]=='<') add(r, 1);
					}
				}
			}
		}
	}
	return 0;
}

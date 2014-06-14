#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> pii;

const int N=3e5+1;
int n, w, t1[N], t2[N], cont[N];
set<pii> s1, s2;
long long ans=0;

void take1(int i, int a) {
	ans += a;
	s1.erase(pii(a, i));
	if(!cont[i]) {
		s1.insert(pii(t2[i]-t1[i], i));
		s2.erase(pii(t2[i], i));
	}
	cont[i]++;
	w--;
}

void take2(int i) {
	ans += t2[i];
	cont[i]=2;
	s2.erase(pii(t2[i], i));
	s1.erase(pii(t1[i], i));
	w-=2;
}

int main() {
	cin>>n>>w;
	for(int i=0;i<n;i++) {
		cin>>t1[i]>>t2[i];
		s1.insert(pii(t1[i], i));
		s2.insert(pii(t2[i], i));
	}
	while(w) {
		if((w & 1) || s1.size() == 1 || s2.size() == 0) {
			pii p = *s1.begin();
			take1(p.second, p.first);
		}
		else {
			pii p1 = *s1.begin();
			pii p2 = *++s1.begin();
			pii p3 = *s2.begin();
			if(p1.first + p2.first <= p3.first) {
				take1(p1.second, p1.first);
				take1(p2.second, p2.first);
			}
			else {
				take2(p3.second);
			}
		}
	}
	cout << ans << endl;
	string s="";
	for(int i=0;i<n;i++) s += '0'+cont[i];
	cout << s << endl;
	return 0;
}

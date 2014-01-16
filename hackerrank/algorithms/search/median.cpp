#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

int main(void){
	int N, x, nr=0, nl=0;
	char c;
	cin >> N;
	map<int, int> l, r;
	for(int i = 0; i < N; i++){
		cin >> c >> x;
		if(c=='a') {
			l[x]++;
			nl++;
		}
		if(c=='r') {
			if(!l.count(x) && !r.count(x)) {
				cout << "Wrong!" << endl;
				continue;
			}
			else {
				if(l.count(x)) {
					l[x]--;
					nl--;
					if(l[x]==0) l.erase(x);
				}
				else {
					r[x]--;
					nr--;
					if(r[x]==0) r.erase(x);
				}
			}
		}
		while(nr < nl) {
			int x = l.rbegin()->first;
			r[x]++; nr++;
			l[x]--; nl--;
			if(l[x]==0) l.erase(x);
		}
		while(nl < nr) {
			int x = r.begin()->first;
			l[x]++; nl++;
			r[x]--; nr--;
			if(r[x]==0) r.erase(x);
		}
		if(nl == 0) cout << "Wrong!" << endl;
		else if(nl > nr) cout << l.rbegin()->first << endl;
		else {
			long long a = r.begin()->first;
			long long b = l.rbegin()->first;
			long long m = a+b;
			if(m%2) printf("%.1lf\n", m/2.0);
			else cout << m/2 << endl;
		}
	}
	return 0;
}

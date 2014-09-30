#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

vector<pii> changes;

vector<int> norm(vector<int> x) {
	int i=-1;
	for(int bit=30;bit>=0;bit--) {
		for(int pos=i+1;pos<x.size();pos++) if(x[pos] & (1<<bit)) {
			if(pos != ++i) {
				changes.push_back(pii(pos, i));
				x[pos] ^= x[i];
				changes.push_back(pii(i, pos));
				x[i] ^= x[pos];
			}
			for(int pos=0;pos<x.size();pos++) if(pos != i) {
				if(x[pos] & (1<<bit)) {
					changes.push_back(pii(pos, i));
					x[pos] ^= x[i];
				}
			}
			break;
		}
	}
	return x;
}
	
int main() {
	int n;
	cin>>n;
	vector<int> x(n), y(n);
	for(int i=0;i<n;i++) scanf("%d", &x[i]);
	for(int i=0;i<n;i++) scanf("%d", &y[i]);
	vector<pii> a, b;
	vector<int> bx = norm(x);
	a = changes;
	changes.clear();
	vector<int> by = norm(y);
	b = changes;
	reverse(b.begin(), b.end());

	int used[33]={0};
	for(int i=0;i<n;i++) if(by[i]) used[__builtin_clz(by[i])]=1;
	for(int i=0;i<n;i++) if(bx[i] && used[__builtin_clz(bx[i])]) {
		for(int j=i-1;j>=0;j--) {
			if(bx[j] && used[__builtin_clz(bx[j])]) break;
			a.push_back(pii(j, j+1));
			bx[j+1] ^= bx[j];
			a.push_back(pii(j+1, j));
			bx[j] ^= bx[j+1];
			a.push_back(pii(j, j+1));
			bx[j+1] ^= bx[j];
		}
	}
	for(int i=0;i<n;i++) {
		if(by[i] != bx[i]) {
			if(!by[i]) {
				bx[i]=0;
				a.push_back(pii(i, i));
			}
			else {
				for(int j=i+1;j<n;j++) if(bx[j] && ((by[i]^bx[i]) & (1<<(31-__builtin_clz(bx[j]))))) {
					bx[i] ^= bx[j];
					a.push_back(pii(i, j));
				}
				if(by[i] != bx[i]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	vector<int> aux=x;
	cout << a.size() + b.size() << endl;
	for(int i=0;i<a.size();i++) {
		cout << a[i].first+1 << " " << a[i].second+1 << endl;
		aux[a[i].first] ^= aux[a[i].second];
	}
	for(int i=0;i<b.size();i++) {
		cout << b[i].first+1 << " " << b[i].second+1 << endl;
		aux[b[i].first] ^= aux[b[i].second];
	}
	return 0;
}

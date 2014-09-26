#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, cnt[2222];
pii v[2222];

void print() {
	for(int i=0;i<n;i++) cout << v[i].second+1 << " "; cout << endl;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		v[i].second=i;
		cin>>v[i].first;
		cnt[v[i].first]++;
	}
	sort(v, v+n);
	int c2=0, c3=0;
	for(int i=1;i<=2000;i++) {
		if(cnt[i]==2) c2++;
		if(cnt[i] > 2) c3++;
	}
	if(c2 >= 2) {
		cout << "YES" << endl;
		print();
		int t=0;
		for(int i=0;i<n;i++) {
			if(cnt[v[i].first] == 2) {
				swap(v[i], v[i+1]);
				print();
				swap(v[i], v[i+1]);
				i++;
				t++;
				if(t==2) return 0;
			}
		}
	}
	if(c3 > 0) {
		cout << "YES" << endl;
		for(int i=0;i<n;i++) {
			if(cnt[v[i].first] > 2) {
				print();
				swap(v[i], v[i+1]);
				print();
				swap(v[i+1], v[i+2]);
				print();
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}

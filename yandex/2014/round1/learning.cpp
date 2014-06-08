#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int M=500000;
int a[5], pos[5];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> v;
	v.push_back(0);
	for(int i=0;i<n;i++) {
		int k = v.size();
		int s[10], sp[10];
		int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
		vector<int> nv;
		for(int j=0;j<v.size();j++) {
			int sum = v[j] + a[i];
			int sz=0;
			while(sum) {
				s[sz++] = sum%10;
				sum /= 10;
			}
			for(int ii=0;ii<sz;ii++) sp[ii]=ii;
			do {
				int num=0;
				for(int ii=0;ii<sz;ii++) num += p10[ii] * s[sp[ii]];
				nv.push_back(num);
			} while(next_permutation(sp, sp+sz));
		}
		v = nv;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}
	cout << v.back() << endl;
	return 0;
}

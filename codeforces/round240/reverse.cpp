#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

ll inv[22], ok[22];
const int N=2e6;
int v[N];

void merge_sort(int a, int b, int n) {
	if(!n) return;
	int m = (a+b)/2;
	merge_sort(a, m, n-1);
	merge_sort(m, b, n-1);
	int i, j;
	j=b-1;
	for(i=m-1;i>=a;i--) {
		while(j >= m && v[j] >= v[i]) j--;
		inv[n] += j-m+1;
	}
	j=m;
	for(i=a;i<m;i++) {
		while(j < b && v[j] <= v[i]) j++;
		ok[n] += b-j;
	}
	inplace_merge(v+a, v+m, v+b);
}

int main() {
	int n;
	cin>>n;
	int nn = 1<<n;
	for(int i=0;i<nn;i++) scanf("%d", &v[i]);
	merge_sort(0, nn, n);
	int q;
	cin>>q;
	while(q--) {
		int x;
		scanf("%d", &x);
		for(int i=0;i<=x;i++) swap(inv[i], ok[i]);
		cout << accumulate(inv, inv+n+1, 0ll) << "\n";
	}
	return 0;
}

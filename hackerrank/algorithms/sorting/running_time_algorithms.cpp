#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans;

void insertionSort(vector<int> v) { 
	for(int i=1;i<v.size();i++) for(int j=i;j>0 && v[j] < v[j-1];j--) swap(v[j], v[j-1]), ans++;
}

int main() {
	int n;
	cin>>n;
	vector<int> v(n, 0);
	for(int i=0;i<n;i++) cin>>v[i];
	insertionSort(v);
	cout<<ans<<endl;
	return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<int> v) { for(int j=0;j<v.size()-1;j++) cout<<v[j]<<" "; cout<<v.back()<<endl; }
void insertionSort(vector<int> v) { 
	for(int i=1;i<v.size();i++) {
		for(int j=i;j>0 && v[j] < v[j-1];j--) swap(v[j], v[j-1]);
		print(v);
	}
}

int main() {
	int n;
	cin>>n;
	vector<int> v(n, 0);
	for(int i=0;i<n;i++) cin>>v[i];
	insertionSort(v);  
	return 0;
}

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

const int N=1e6+10;
int vis[N];

int main() {
	for(int i=2;i<N;i++) {
		if(!vis[i]) for(int j=i+i;j<N;j+=i) vis[j]=1;
	}
	int n;
	cin>>n;
	for(int i=4;i<n;i++) {
		if(vis[i] && vis[n-i]) {
			cout << i << " " << n-i << endl;
			return 0;
		}
	}
}

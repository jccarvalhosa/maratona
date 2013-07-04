#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

#define M 3000001
int vis[M];

int main() {
	int n, i, k=0, j;
	cin>>n;
	for(i=2;i<M && k<n;i++) {
		if(!vis[i]) {
			cout<<i<<endl;
			k++;
		}
		for(j=2*i;j<M;j+=i) vis[j]=1; 
	}
	cout<<endl;
	return 0;
}

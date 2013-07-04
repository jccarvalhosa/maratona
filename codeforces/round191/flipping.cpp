#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int v[110];

int main() {
	int n, best=0, i, j, k, aux;
	cin>>n;
	for(i=1;i<=n;i++) cin>>v[i];
	for(i=1;i<=n;i++) {
		for(j=i;j<=n;j++) {
			aux=0;
			for(k=1;k<=n;k++) {
				if(k>=i && k<=j) aux += 1-v[k];
				else aux += v[k];
			}
			best = max(best, aux);
		}
	}
	cout<<best<<endl;
	return 0;
}

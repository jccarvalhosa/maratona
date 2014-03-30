#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

pii v[1111];

int main() {
	int n;
	while(cin>>n && n) {
		for(int i=0;i<n;i++) {
			cin>>v[i].first;
			v[i].second=i;
		}
		sort(v, v+n);
		cout<<v[n-2].second+1<<endl;
	}
	return 0;
}

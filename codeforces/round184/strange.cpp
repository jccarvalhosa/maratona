#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

int main() {
	int n, i, a[100];
	vector<int> v;
	cin>>n; 
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) if(a[i]>=1 && a[i]<=9) {
		v.pb(a[i]);
		break;
	}
	for(i=0;i<n;i++) if(a[i]!=0 && a[i]!=100 && a[i]%10 == 0) {
		v.pb(a[i]);
		break;
	}
	if(v.size() == 0) for(i=0;i<n;i++) if(a[i] % 10 != 0 && a[i] > 10) {
		v.pb(a[i]);
		break;
	}
	for(i=0;i<n;i++) if(a[i]==0) {
		v.pb(a[i]);
		break;
	}
	for(i=0;i<n;i++) if(a[i]==100) {
		v.pb(a[i]);
		break;
	}
	cout << v.size() << endl;
	cout << v[0];
	for(i=1;i<v.size();i++) cout << " " << v[i];
	cout << endl;
	return 0;
}

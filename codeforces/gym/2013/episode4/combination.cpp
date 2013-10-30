#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		if(accumulate(v.begin(), v.end(), 0) % n == 0) cout << "Sepehr" << endl;
		else cout << "Sohrab" << endl;
	}
	return 0;
}

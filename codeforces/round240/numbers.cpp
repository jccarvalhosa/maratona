#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	if(n == 1) {
		if(k==0) cout<<1<<endl;
		else cout<<-1<<endl;
	}
	else if(k < n/2) {
		cout << -1 << endl;
	}
	else {
		int i;
		vector<int> ans;
		for(i=1;;i++) {
			if(n <= 3) break;
			ans.push_back(2*i-1);
			ans.push_back(2*i);
			n -= 2;
			k--;
		}
		int x = 2*i+1;
		int c = (x+k-1)/k;
		ans.push_back(c*k);
		ans.push_back(c*k+k);
		if(n & 1) ans.push_back(c*k+k+1);
		cout<<ans[0];
		for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}

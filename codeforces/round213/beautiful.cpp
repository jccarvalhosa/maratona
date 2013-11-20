#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
	
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

int main() {
	int n;
	cin>>n;
	vector<int> ans(1, 1);
	for(int i=0;ans.size() < n;i++) for(int j=0;j<ans.size();j++) if(primes[i]*ans[j] <= 2*n*n) ans.push_back(primes[i]*ans[j]);
	sort(ans.begin(), ans.end(), greater<int>());
	cout<<ans[0];
	for(int i=1;i<n;i++) cout<<" "<<ans[i]; cout<<endl;
	return 0;
}

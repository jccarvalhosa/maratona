#include <iostream>
using namespace std;

const int MID = 5e6;
const int N=1e7;

int cont[N];

int main() {
	int n;
	string s;
	cin>>n>>s;
	int sum=0;
	long long ans=0;
	cont[MID] = 1;
	for(int i=0;i<n;i++) {
		if(s[i] == 'C') sum += 1;
		else sum -= 2;
		ans += cont[MID + sum];
		cont[MID + sum]++;
	}
	cout << ans << endl;
	return 0;
}

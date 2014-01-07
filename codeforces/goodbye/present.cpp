#include <iostream>
using namespace std;

int main() {
	int n, a[333];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) {
		if(i) cout<<"R";
		while(a[i]) {
			cout<<"P";
			a[i]--;
			if(!i) cout<<"RL";
			else cout<<"LR";
		}
	}
	cout<<endl;
	return 0;
}

#include <cstdio>
#include <iostream>
using namespace std;

int v[111111];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>v[i];
		v[i] /= 25;
	}
	int num[10] = {0};
	int i;
	for(i=0;i<n;i++) {
		if(v[i] == 1) num[1]++;
		if(v[i] == 2) {
			num[2]++;
			num[1]--;
			if(num[1] < 0) break;
		}
		if(v[i] == 4) {
			if(num[2] != 0) {
				num[2]--;
				v[i] -= 2;
			}
			num[1] -= v[i]-1;
			if(num[1] < 0) break;
		}
	}
	if(i!=n) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}

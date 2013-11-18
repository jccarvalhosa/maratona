#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int v[5555];
int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>v[i];
	sort(v, v+m);
	if(v[0]==1 || v[m-1]==n) cout<<"NO"<<endl;
	else {
		int valid=1;
		for(int i=0;i<m-2;i++) if(v[i+1]-v[i]==1 && v[i+2]-v[i]==2) {valid=0; break;}
		if(valid) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

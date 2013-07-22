#include <iostream>
using namespace std;

int cont[111];
int n, x, g, c=0, u=0, s=0;

int check() {
	if(s!=2*n-2) return 0;
	if(c==0) return 1;
	if(c==1) {
		if(g==2) return 1;
		if(cont[g] <= 3) return 1;
		return 2;
	}
	if(c==2) {
		if(u==2) return 1;
		return 2;
	}
	return 2;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>x;
		s += x;
		cont[x]++;
	}
	for(int i=2;i<n;i++) {
		if(cont[i]) {
			c++;
			g=i;
		}
		if(cont[i]==1) u++;
	}
	int valid = check();
	if(valid==0) cout<<"None"<<endl;
	if(valid==1) cout<<"Unique"<<endl;
	if(valid==2) cout<<"Multiple"<<endl;
	return 0;
}

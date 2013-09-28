#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int v[10];

int main() {
	int n;
	cin>>n;
	int m=1<<30;
	for(int i=1;i<10;i++) {
		cin>>v[i];
		m = min(m, v[i]);
	}
	int valid=0;
	int tam = n / m;
	for(int i=1;i<=tam;i++) {
		for(int d=9;d>=1;d--) {
			if(n < v[d]) continue;
			int tam2 = (n - v[d])/m;
			if(i + tam2 == tam) {
				cout<<d;
				valid=1;
				n -= v[d];
				break;
			}
		}
	}
	if(!valid) cout<<-1<<endl;
	cout<<endl;
	return 0;
}

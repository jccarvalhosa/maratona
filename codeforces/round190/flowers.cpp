#include <cstdio>
#include <iostream>
using namespace std;

int cont[3];

int main() {
	int a, b, c, t=0;
	cin>>a>>b>>c;
	cont[a%3]++;
	cont[b%3]++;
	cont[c%3]++;
	if(a<3||b<3||c<3) {}
	else if(cont[2]>=2) {
		t += 2;
		a -= 2;
		b -= 2;
		c -= 2;
	}
	else if(cont[1]>=2) {
		t += 1;
		a -= 1;
		b -= 1;
		c -= 1;
	}
	cout << (t + a/3 + b/3 + c/3) << endl;
	return 0;
}

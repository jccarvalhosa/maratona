#include <iostream>
using namespace std;

int main() {
	double a, b, c, d;
	cin>>a>>b>>c>>d;
	cout<<(a/b)/(1.0 - (1.0-a/b)*(1.0-c/d));
	return 0;
}

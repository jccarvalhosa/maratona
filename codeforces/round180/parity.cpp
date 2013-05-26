#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	int i, ua=0, ub=0;
	cin >> a >> b;
	for(i=0;i<a.size();i++) if(a[i]=='1') ua++;
	for(i=0;i<b.size();i++) if(b[i]=='1') ub++;
	if(ua%2==1) ua++;
	cout << (ub>ua?"NO":"YES") << endl;
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	int sum=0;
	while(T--) {
		int valid=0;
		double l, wi, d, we;
		cin>>l>>wi>>d>>we;
		if(l < 56+1e-9 && wi < 45+1e-9 && d < 25+1e-9) valid=1;
		if(l + wi + d < 125+1e-9) valid=1;
		if(we >= 7+1e-9) valid=0;
		cout<<valid<<endl;
		sum += valid;
	}
	cout<<sum<<endl;
	return 0;
}

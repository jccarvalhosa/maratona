#include <iostream>
using namespace std;

const int N=6001;
int col[N], row[N], tcol[N], trow[N];

int main() {
	int n, p;
	cin>>n>>p;
	for(int i=1;i<=p;i++) {
		string s;
		int a, b;
		cin>>s>>a>>b;
		if(s == "COL") {
			col[a] = b;
			tcol[a] = i;
		}
		else {
			row[a] = b;
			trow[a] = i;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		if(tcol[i] > trow[j]) {
			ans += col[i];
		}
		else {
			ans += row[j];
		}
	}
	cout << ans << endl;
	return 0;
}

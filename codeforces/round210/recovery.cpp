#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int M = (int)(1e9);
int op[5000][4];

int main() {
	int n, m;
	cin>>n>>m;
	vector<ll> lim(n, M);
	for(int i=0;i<m;i++) {
		for(int j=0;j<4;j++) cin>>op[i][j];
		op[i][1]--; op[i][2]--;
	}
	int valid=1;
	for(int i=0;i<m;i++) {
		if(op[i][0]==1) for(int j=op[i][1];j<=op[i][2];j++) lim[j] += op[i][3];
		if(op[i][0]==2) {
			int good=0;
			for(int j=op[i][1];j<=op[i][2];j++) {
				if(lim[j] >= op[i][3]) good=1;
				lim[j] = min(lim[j], 1ll*op[i][3]);
			}
			if(!good) valid=0;
		}
	}
	for(int i=m-1;i>=0;i--) {
		if(op[i][0]==1) for(int j=op[i][1];j<=op[i][2];j++) lim[j] -= op[i][3];
		if(op[i][0]==2) {
			int good=0;
			for(int j=op[i][1];j<=op[i][2];j++) if(lim[j] == op[i][3]) good=1;
			if(!good) valid=0;
		}
	}
	for(int i=0;i<n;i++) if(lim[i] < -M) valid=0;
	if(!valid) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		cout<<lim[0];
		for(int i=1;i<n;i++) cout<<" "<<lim[i]; cout<<endl;
	}
	return 0;
}

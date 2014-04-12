#include <iostream>
using namespace std;

int can[20];

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cout << "Case #"<<t<<": ";
		for(int i=1;i<=16;i++) can[i]=1;
		for(int tt=0;tt<2;tt++) {
			int line;
			cin>>line;
			for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) {
				int x;
				cin>>x;
				if(i!=line) can[x]=0; 
			}
		}
		int n=0;
		int ans;
		for(int i=1;i<=16;i++) if(can[i]) ans=i, n++;
		if(n == 0) cout << "Volunteer cheated!\n";
		else if(n == 1) cout << ans << endl;
		else cout << "Bad magician!\n";
	}
	return 0;
}

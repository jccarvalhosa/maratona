#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 500001;
int v[50], valid[M], days[M];

int main() {
	int n, d;
	cin>>n>>d;
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v, v+n);
	valid[0]=1;
	for(int i=0;i<n;i++) {
		int can=0, d1=M;
		for(int j=0;j<M;j++) if(valid[j] && !(j + d < v[i])) can=1;
		if(can) for(int j=M-v[i]-1;j>=0;j--) if(valid[j]) valid[j+v[i]]=1;
	}
	for(int i=0;i<M;i++) days[i] = 1<<30;
	days[0]=0;
	for(int i=1;i<=d;i++) if(valid[i]) days[i]=1;
	for(int i=d+1;i<M;i++) if(valid[i]) for(int j=i-d;j<=i;j++) if(valid[j]) { days[i] = days[j] + 1; break; }
	for(int i=M-1;i>=0;i--) if(valid[i]){
		cout<<i<<" "<<days[i]<<endl;
		break;
	}
	return 0;
}

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define M 1000000
#define NMAX 300000

vector<int> factors[1111111];
int vis[1111111], pos[1111111], ans[333333], c;

int main() {
	int n=1, x=2;
	ans[1]=1;
	for(int i=2;i<=M;i++) if(!vis[i]) for(int j=i;j<=M;j+=i) {
		vis[j]=1;
		factors[j].push_back(i);
	}
	for(int i=0;i<=M;i++) vis[i]=0;
	vis[1]=1;
	for(int i=0;i<=M;i++) pos[i]=1;
	c=1;
	while(1) {
		vis[x]=1;
		n++;
		if(x <= NMAX) {
			ans[x] = n;
			c++;
			if(c==NMAX) break;
		}
		int m=M;
		for(int i=0;i<factors[x].size();i++) {
			int d = factors[x][i];
			while(d*pos[d] <= M && vis[d*pos[d]] == 1) pos[d]++;
			m = min(m, d*pos[d]);
		}
		x=m;
	}
	while(1) {
		cin>>n;
		if(n==0) return 0;
		cout<<"The number "<<n<<" appears in location "<<ans[n]<<".\n";
	}
}

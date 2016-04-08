#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=1000001;
int n, t[N];

void add(int x, int v) { for(;x<N;x+=x&-x) t[x]+=v; }
int sum(int x) { int ret=0; for(;x;x-=x&-x) ret+=t[x]; return ret; }

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<N;i++) t[i]=0;
		long long ans=0;
		for(int i=1;i<=n;i++) {
			int x;
			cin>>x;
			add(x, 1);
			ans += i - sum(x);
		}
		cout<<ans<<endl;
	}
	return 0;
}


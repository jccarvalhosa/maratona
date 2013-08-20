#include <iostream>
#include <cstdio>
using namespace std;

int grau[111], vis[11111];

int main() {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		for(int i=1;i<=n;i++) grau[i]=0;
		int total=0;
		for(int i=0;i<k;i++) {
			int a, b;
			cin>>a>>b;
			grau[a]++;
			grau[b]++;
			total += 2;
		}
		for(int i=0;i<=total;i++) vis[i]=0;
		vis[0]=1;
		for(int i=1;i<=n;i++) for(int j=total;j>=0;j--) if(vis[j]) vis[j+grau[i]]=1;
		cout<<(vis[k]?"S":"N")<<endl;
	}
	return 0;
}

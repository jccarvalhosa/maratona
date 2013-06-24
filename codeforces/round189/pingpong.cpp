#include <cstdio>
#include <iostream>
using namespace std;

int n, val[300][2];
int vis[300];

void dfs(int v) {
	vis[v]=1;
	for(int u=0;u<n;u++) 
		if(!vis[u] && ((val[u][0]<val[v][0] && val[v][0]<val[u][1]) || (val[u][0]<val[v][1] && val[v][1]<val[u][1]))) 
			dfs(u);
}


int main() {
	int t, c, a, b, i;
	cin>>t;
	while(t--) {
		cin>>c>>a>>b;
		if(c==1) {
			val[n][0]=a;
			val[n][1]=b;
			n++;
		}
		if(c==2) {
			if(a>n||b>n) cout<<"NO"<<endl;
			else {
				for(i=0;i<n;i++) vis[i]=0;
				dfs(a-1);
				if(vis[b-1]) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}

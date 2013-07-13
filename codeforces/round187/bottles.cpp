#include <iostream>
#include <algorithm>
using namespace std;

int ans, vis[101], a[101], b[101];

int main() {
	int n, i, j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(i!=j && b[i]==a[j]) vis[j]=1;
	for(i=1;i<=n;i++) if(!vis[i]) ans++;
	cout<<ans<<endl;
	return 0;
}

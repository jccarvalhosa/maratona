#include <cstdio>
#include <iostream>
using namespace std;

int num[] = {1, 4, 9, 121, 484};

int main() {
	int T, t, i, j, a, b, ans;
	cin>>T;
	for(t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		cin>>a>>b;
		ans=0;
		for(i=a;i<=b;i++) for(j=0;j<5;j++) if(i == num[j]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}

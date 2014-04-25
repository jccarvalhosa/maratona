#include <cstdio>

int main() {
	freopen("jenga.in","r",stdin);
	int T;
	scanf("%d",&T);
	for(int t =0; t < T; t++) {
		int N;
		scanf("%d",&N);
		if(N%3 != 0) printf("Case %d: Bakkar\n",t+1);
		else printf("Case %d: Wahdan\n",t+1);
	}
	return 0;
}

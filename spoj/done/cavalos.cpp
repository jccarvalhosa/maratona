#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	if(N > M) swap(N, M);
	if(N == 1) printf("%d", M);
	if(N == 2) printf("%d", 2*(2*(M/4) + min(2, M%4)));
	if(N > 2) printf("%d", (N*M+1)/2);
	return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

int stack[100000];

int main() {
	int n, v, ans=0, top=-1;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &v);
		while(top != -1 && stack[top] < v) ans = max(ans, v ^ stack[top--]);
		if(top != -1) ans = max(ans, v ^ stack[top]);
		stack[++top] = v;
	}
	printf("%d\n", ans);
	return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1000000000

using namespace std;

vector<int> ans;

int main()
{
	int i, a, b;
	int t=1;
	while(scanf("%d %d", &a, &b) && (a || b))
	{
		ans.clear();
		for(i=1; ; i++) {
			int n = i*(i+1)/2;
			if(n+1 <= a) continue;
			if(n+1 >= b) break;
			int x = sqrt(n+1);
			if(x*x == n+1) ans.push_back(n+1);
		}
		printf("Case %d: %d\n", t++, (int)ans.size());
	}
	return 0;
}

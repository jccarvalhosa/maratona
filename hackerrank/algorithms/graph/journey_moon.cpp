#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

int sum(int v, vector<vector<int> >& pairs, vector<int>& vis) {
	if (vis[v]) return 0;
	vis[v] = 1;
	int ans = 1;
	for(int i=0; i < pairs[v].size(); i++) {
		int u = pairs[v][i];
		ans += sum(u, pairs, vis);
	}
	return ans;
}

int main()
{ 
	int N, I;
	cin >> N >> I;
	vector<vector<int> > pairs(N);
	vector<int> vis(N, 0);
	for (int i = 0; i < I; ++i) {
		int a, b;
		cin >> a >> b;
		pairs[a].push_back(b);
		pairs[b].push_back(a);
	}

	long long result = 1ll * N * (N-1) / 2;
	for (int i = 0; i < N; i++) {
		long long sz = sum(i, pairs, vis);
		result -= sz * (sz-1) / 2;
	}

	cout << result << endl;
	return 0;
}

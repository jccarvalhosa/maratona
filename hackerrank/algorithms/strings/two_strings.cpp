#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int T;
	cin>>T;
	int N = 'z'-'a'+1;
	while(T--) {
		vector<bool> hasA(N, false), hasB(N, false);
		string a, b;
		cin>>a>>b;
		int na = a.size(), nb = b.size();
		for (int i=0; i < na; i++)
			hasA[a[i] - 'a'] = true;
		for (int i=0; i < nb; i++)
			hasB[b[i] - 'a'] = true;

		bool hasCommon = false;
		for (int i = 0; i < N; i++)
			if (hasA[i] && hasB[i])
				hasCommon = true;

		cout << (hasCommon ? "YES" : "NO") << endl;
	}
	return 0;
}


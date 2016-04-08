#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans(string &s, int i, int f, bool canRemove) {
	if (i >= f)
		return -1;

	if (s[i] == s[f])
		return ans(s, i+1, f-1, canRemove);

	if (!canRemove)
		return -2;

	if (ans(s, i+1, f, false) == -1)
		return i;

	if (ans(s, i, f-1, false) == -1)
		return f;

	return -2;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		string s;
		cin>>s;
		n = s.size();
		cout << ans(s, 0, n-1, true) << endl;
	}
	return 0;
}


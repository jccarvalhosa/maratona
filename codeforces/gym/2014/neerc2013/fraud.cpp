#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {
	int i, j, n;
	char s[22], c[22];
	vector<string> v;
	freopen("fraud.in", "r", stdin);
	freopen("fraud.out", "w", stdout);
	scanf("%s %d", s, &n);
	for(i=0; i<n; i++) {
		scanf("%s", c);
		for(j=0; c[j]; j++) if(s[j]!='*' && s[j]!=c[j]) break;
		if(j==9) v.push_back(c);
	}
	printf("%d\n", (int)v.size());
	for(i=0; i<v.size(); i++) printf("%s\n", v[i].c_str());
	return 0;
}

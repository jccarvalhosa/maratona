#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; t++) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", t);

		if (n == 0) {
			printf("INSOMNIA\n");
			continue;
		}

		vector<int> vis(10, 0);
		int sum = 0;

		for (int i=1; ; i++) {
			stringstream ss;
			ss << (1ll * i * n);
			string s = ss.str();
			for (int j=0; j < s.size(); j++) {
				int c = s[j] - '0';
				if (vis[c]) continue;
				vis[c] = 1;
				sum++;
			}
			if (sum == 10) {
				cout << s << endl;
				break;
			}
		}
	}
	return 0;
}

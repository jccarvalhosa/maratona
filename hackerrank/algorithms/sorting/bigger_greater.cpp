#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char cmax[111];

int main() {
	string s;
	int T;
	cin >> T;
	while(T--) {
		cin>>s;
		bool found = false;

		int n = s.size();
		cmax[n-1] = s[n-1];
		for (int i = n-2; i >= 0; i--) {
			cmax[i] = max(s[i], cmax[i+1]);
		}

		for (int i = n - 2; i >= 0; i--) if (s[i] < cmax[i+1]) {                
			string before = "";
			if (i != 0) {
				before = s.substr(0, i);
			}           

			int best = -1;
			for (int j = i+1; j < n; j++) 
				if (s[j] > s[i] && (best == -1 || s[j] < s[best]))
					best = j;

			string after = "";
			for (int j = i; j < n; j++) if (j != best) {
				after += s[j];
			}
			sort(after.begin(), after.end());

			cout << before << s[best] << after << endl;

			found = true;
			break;
		}

		if (!found)
			cout << "no answer" << endl;
	}
	return 0;
}

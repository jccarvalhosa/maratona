#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 1000000000;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> x(n), y(n), z(n);
		for(int i=0;i<n;i++) cin >> x[i] >> y[i] >> z[i];
		bool colinear = true;
		vector<bool> top(n, false);
		for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) {
			int a = (y[i] - y[k]) * (z[j] - z[k]) - (z[i] - z[k]) * (y[j] - y[k]);
			int b = (z[i] - z[k]) * (x[j] - x[k]) - (x[i] - x[k]) * (z[j] - z[k]);
			int c = (x[i] - x[k]) * (y[j] - y[k]) - (y[i] - y[k]) * (x[j] - x[k]);
			if (a != 0 || b != 0 || c != 0) {
				colinear = false;
				for (int l = -1; l <= 1; l+=2) {
					int maxval = -inf;
					for(int ind=0;ind<n;ind++) maxval = max(maxval, l * a * x[ind] + l * b * y[ind] + l * c * z[ind]);
					for(int ind=0;ind<n;ind++) if (l * a * x[ind] + l * b * y[ind] + l * c * z[ind] == maxval) top[ind] = true;
				}
			}
		}
		for (int i = 0; i < n; i++)	cout << ((top[i] || colinear) ? 'T' : 'F');
		cout << endl;
	}
	return 0;
}

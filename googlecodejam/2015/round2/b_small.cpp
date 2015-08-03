#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef pair<double, double> pdd;

double r[111], c[111];
int n;

double solve(int index, double v, double x, double ans) {
	if(index > n) return ans;
	if(c[index] > x + 1e-6) return 1e9;
	if(c[index] > x - 1e-6) return min(ans, v / r[index]);

}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		double v, x;
		cin>>v>>x;
		vector<pdd> aux;
		for(int i=0;i<n;i++) {
			double ri, ci;
			cin>>ri>>ci;
			aux.push_back(pdd(ci, ri));
		}
		sort(aux.begin(), aux.end());
		c[0] = aux[0].first;
		r[0] = aux[0].second;
		n=1;
		for(int i=1;i<aux.size();i++) {
			if(fabs(c[n-1], aux[i].first) < 1e-9) {
				r[n-1] += aux[i].second;
			} else {
				c[n] = aux[i].first;
				r[n] = aux[i].second;
				n++;
			}
		}
		double sol = solve(0, v, x, 1e9);
		if(requal > 0) sol = v/requal;
		if(n==2) {
			double va = v * (x - c[1]) / (c[0] - c[1]);
			double vb = v * (c[0] - x) / (c[0] - c[1]);
			if(va > -1e-12 && vb > -1e-12) {
				sol = min(sol, max(va/r[0], vb/r[1]));
			}
		}
		if(sol == 1e9) {
			cout << "Case #"<<t<<": IMPOSSIBLE"<<endl; 
		}
		else {
			printf("Case #%d: %.12lf\n", t, sol);
		}
	}
	return 0;
}

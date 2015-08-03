#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
	
int n;
double p[111];
double sum[111];

int main() {
	cin>>n;
	double best=0;
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n;i++) {
		double prob = p[i];
		best = max(best, prob);
		for(int j=i+1;j<n;j++) {
			prob = 0;
			prob += p[i] * (1-p[j]);
			prob += (1-p[i]) * p[j];
			best = max(best, prob);
			for(int k=j+1;k<n;k++) {
				prob = 0;
				prob += p[i] * (1-p[j]) * (1-p[k]);
				prob += (1-p[i]) * p[j] * (1-p[k]);
				prob += (1-p[i]) * (1-p[j]) * p[k];
				best = max(best, prob);
				for(int l=k+1;l<n;l++) {
					prob = 0;
					prob += p[i] * (1-p[j]) * (1-p[k]) * (1-p[l]);
					prob += (1-p[i]) * p[j] * (1-p[k]) * (1-p[l]);
					prob += (1-p[i]) * (1-p[j]) * p[k] * (1-p[l]);
					prob += (1-p[i]) * (1-p[j]) * (1-p[k]) * p[l];
					best = max(best, prob);
				}
			}
		}
	}
	printf("%.12lf\n", best);
	return 0;
}

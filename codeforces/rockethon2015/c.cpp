#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

double dp[10001][5];
double sum[10001][5];

int main() {
	int n;
	int a[5], b[5], cnt[5];
	cin>>n;
	int amin=100000, bmax=0;
	for(int i=0;i<n;i++) {
		cin>>a[i]>>b[i];
		cnt[i] = b[i]-a[i]+1;
		amin = min(amin, a[i]);
		bmax = max(bmax, b[i]);
	}
	double avg=0;
	for(int f=amin;f<=bmax;f++) {
		double p=1, p1=1;
		for(int j=0;j<n;j++) {
			p = p * max(0, min(cnt[j], min(f, b[j]) - a[j]) + 1) / cnt[j];
			p1 = p1 * max(0, min(cnt[j], min(f-1, b[j]) - a[j]) + 1) / cnt[j];
		}
		p -= p1;
		for(int i=0;i<n;i++) if(a[i] <= f && b[i] >= f) {
			double p1=1;
			for(int j=0;j<n;j++) if(j != i) {
				p1 = p1 * max(0, min(cnt[j], min(f-1, b[j]) - a[j]) + 1) / cnt[j];
			}
			p -= p1 / cnt[i];
		}
		avg += p * f;
	}
	for(int s=1;s<=10000;s++) for(int i=0;i<n;i++) {
		double p1 = 1.0/cnt[i], p2 = 1.0/cnt[i];
		for(int j=0;j<n;j++) if(j != i) {
			p1 = p1 * max(0, min(cnt[j], min(s, b[j]) - a[j]) + 1) / cnt[j];
			p2 = p2 * max(0, min(cnt[j], min(s-1, b[j]) - a[j]) + 1) / cnt[j];
		}
		dp[s][i] = (p1-p2) * s;
		sum[s][i] = sum[s-1][i] + dp[s][i];
	}
	for(int i=0;i<n;i++) for(int f=a[i];f<=b[i];f++) avg += sum[f-1][i];
	printf("%.12lf\n", avg);
	return 0;
}

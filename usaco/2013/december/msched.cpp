#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int M=10000;
int t[M+1];
pii cow[M+1];

int main() {
	ifstream in("msched.in");
	ofstream out("msched.out");
	int n;
	in>>n;
	for(int i=0;i<n;i++) in>>cow[i].first>>cow[i].second;
	sort(cow, cow+n, greater<pii>());
	int ans=0;
	for(int i=0;i<n;i++) {
		int g = cow[i].first;
		int d = cow[i].second;
		int j;
		for(j=d;j<=M;j++) if(t[j]==j) break;
		if(j < M) continue;
		for(j=d;j<=M;j++) t[j]++;
		ans += g;
	}
	out<<ans<<endl;
	return 0;
}

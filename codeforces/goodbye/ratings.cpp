#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int N=333333;
pii a[N];
int b[N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a, a+n);
	int old=a[0].first;
	b[a[0].second] = old;
	for(int i=1;i<n;i++) {
		old = max(old+1, a[i].first);
		b[a[i].second] = old; 
	}
	for(int i=0;i<n-1;i++) cout<<b[i]<<" "; cout<<b[n-1]<<endl;
	return 0;
}

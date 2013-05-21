#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> q;

int main() {
	int n, a, i, c=0, l=-1, t;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>a;
		q.push(-a);
	}
	while(!q.empty()) {
		a = -q.top();
		q.pop();
		if(l != a) {
			l = a;
			t = 1;
			c++;
		} else {
			t++;
			if(t == 1) c++;
			if(t == 2) {
				t = 0;
				c--;
				q.push(-a-1);
			}
		}
	}
	cout << a-c+1 << endl;
	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int k, n1, n2, n3, t1, t2, t3;
	cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
	int t=0;
	queue<int> q1, q2, q3;
	while(k > 0 || !q1.empty() || !q2.empty() || !q3.empty()) {
		while(!q3.empty() && t - q3.front() >= t3) {
			q3.pop();
		}
		while(!q2.empty() && t - q2.front() >= t2) {
			if(q3.size() == n3) break;
			q3.push(t);
			q2.pop();
		}
		while(!q1.empty() && t - q1.front() >= t1) {
			if(q2.size() == n2) break;
			q2.push(t);
			q1.pop();
		}
		while(k > 0 && q1.size() != n1) {
			q1.push(t);
			k--;
		}
		t++;
	}
	cout << t-1 << endl;
	return 0;
}

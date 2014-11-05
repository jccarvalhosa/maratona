#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

ll k, sum, ans;
int n, c;

void solve(int p) {
	sum=0;
	c=0;
	priority_queue<int> q;
	for(int i=1;i<=n;i++) {
		sum += i;
		q.push(i);
	}
	ans = sum;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<q.top();j+=i+1) {
			q.push(j);
			sum += j;
		}
		while(q.size() != n) {
			sum -= q.top();
			q.pop();
		}
		if(ans > sum + k*i) {
			ans = sum + k*i;
			c = i;
		}
		if(i==p) {
			c=0;
			ll delta=1;
			for(int i=1;i<=n;i++) {
				int t = q.top();
				if(delta > t) {
					cout<<i-1<<" ";
					c++;
					delta = 2+c;
				}
				else {
					if(delta == t) q.pop();
					delta += 1+c;
				}
			}
			cout<<endl;
			return;
		}
	}
}


int main() {
	cin>>n>>k;
	solve(-1);
	cout << ans << endl;
	cout << c << endl;
	solve(c);
	return 0;
}

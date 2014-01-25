#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		stack<int> pos;
		queue<int> ord;
		for(int i=1;i<=n;i++) {
			int x;
			cin>>x;
			ord.push(x);
			pos.push(i);
			while(!ord.empty() && ord.front()==pos.top()) {
				ord.pop();
				pos.pop();
			}
		}
		if(ord.empty()) cout<<"Valid"<<endl;
		else cout<<"Invalid"<<endl;
	}
	return 0;
}

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int root[1001], child[1001], valid[1001];

int main() {
	int n, i, j, v, x, pos, t, flag;
	cin>>n>>x;
	vector<int> num;
	for(i=1;i<=n;i++) {
		cin>>v;
		if(!v) root[i]=1;
		else child[v] = i;
	}
	for(i=1;i<=n;i++) if(root[i]) {
		t=0;
		flag=0;
		for(v=i;v;v=child[v]) {
			t++;
			if(x==v) {
				pos=t;
				flag=1;
			}
		}
		if(!flag) num.push_back(t);
	}
	valid[0]=1;
	for(j=0;j<num.size();j++) {
		v = num[j];
		for(i=n;i>=v;i--) if(valid[i-v]) valid[i]=1;
	}
	for(i=0;i<=n;i++) if(valid[i]) cout << i+pos<<endl;
	return 0;
}

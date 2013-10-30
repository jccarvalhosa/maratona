#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int t[4];

struct pc {
	int w, t, i;
};

struct cmp {
	bool operator()(const pc &a, const pc &b)const { return a.w > b.w; }
};

priority_queue <pc,vector<pc>, cmp> q;
vector <pc> ans[4];

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	t[1] = a;
	t[2] = b;
	t[3] = a+b;
	for(int i=0;i<n;i++) {
		pc p;
		cin >> p.t >> p.w;
		p.i = i+1;
		q.push(p);
	}
	int r=0, w=0;
	while(t[3] && !q.empty()) {
		pc p = q.top();
		q.pop();
		if(t[p.t] > 0) {
			ans[p.t].push_back(p);
			w += p.w;
			r++;
			if(p.t != 3) t[p.t]--;
			t[3]--;
		}
	}
	int i;
	cout << r << " " << w << endl;
	for(i=0;i<ans[1].size();i++) cout << ans[1][i].i << " " << i+1 << endl;
	for(int k=0;k<ans[3].size();i++, k++) cout << ans[3][k].i << " " << i+1 << endl;
	if(i < a) i = a;
	for(int k=0;k<ans[2].size();i++, k++) cout << ans[2][k].i << " " << i+1 << endl;
	return 0;
}

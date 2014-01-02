#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct player {
	int height, shot;
	string name;
};

bool cmp(const player &a, const player &b) {
	if(a.shot != b.shot) return a.shot > b.shot;
	return a.height > b.height;
}
		
int n, m, p;
vector<string> names;

void simulate(vector<player> v) {
	queue<player> in, out;
	for(int i=p-1;i>=0;i--) in.push(v[i]);
	for(int i=p;i<v.size();i++) out.push(v[i]);
	for(int i=0;i<m;i++) {
		out.push(in.front());
		in.pop();
		in.push(out.front());
		out.pop();
	}
	for(; !in.empty(); in.pop()) names.push_back(in.front().name);
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n>>m>>p;
		vector<player> v(n);
		for(int i=0;i<n;i++) cin>>v[i].name>>v[i].shot>>v[i].height;
		sort(v.begin(), v.end(), cmp);
		vector<player> t1, t2;
		for(int i=0;i<n;i++) {
			if(i%2) t1.push_back(v[i]);
			else t2.push_back(v[i]);
		}
		names.clear();
		simulate(t1);
		simulate(t2);
		sort(names.begin(), names.end());
		cout<<"Case #"<<t<<":";
		for(int i=0;i<names.size();i++) cout<<" "<<names[i];
		cout<<endl;
	}
	return 0;
}

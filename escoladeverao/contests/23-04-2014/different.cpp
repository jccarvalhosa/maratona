#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int N=5e4+10;
const int M=1e5;
string w[N];
int f[5][222];
vector<int> v[33];

int main() {
	int n;
	srand(time(NULL));
	cin>>n;
	for(int i=0;i<n;i++) cin>>w[i];
	set<pii> s;
	for(int t=0;t<800;t++) {
		for(int j=0;j<5;j++) for(int i=0;i<222;i++) f[j][i] = rand()%2;
		for(int i=0;i<=32;i++) v[i].clear();
		for(int i=0;i<n;i++) {
			int h=0;
			for(int j=0;j<5;j++) h += (1<<j)*f[j][w[i][j]];
			v[h].push_back(i);
		}
		for(int i=0;i<32;i++) {
			int j = 31^i;
			if(j>i) continue;
			for(int ii=0;ii<v[i].size();ii++) for(int jj=0;jj<v[j].size();jj++) {
				int a = v[i][ii];
				int b = v[j][jj];
				if(a>b) swap(a, b);
				s.insert(pii(a+1, b+1));
				if(s.size() == M) goto end;
			}
		}
	}
	end:
		cout<<s.size()<<endl;
		for(set<pii>::iterator it=s.begin();it!=s.end();it++) cout<<(*it).first<<" "<<(*it).second<<endl;
	return 0;
}

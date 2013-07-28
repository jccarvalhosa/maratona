#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mod(int a) { return a>0?a:-a; }

string name[] = {"$20", "$10", "$5", "$2", "$1", "50c", "20c", "10c", "5c"};
int value[] = {2000, 1000, 500, 200, 100, 50, 20, 10, 5};

int main() {
	int n1, c1, n2, c2;
	while(1) {
		scanf("%d.%d %d.%d", &n1, &c1, &n2, &c2);
		if(n1+c1+n2+c2==0) break;
		int v1 = 100*n1 + c1;
		int v2 = 100*n2 + c2;
		int c = mod(v1-v2);
		int x=c%5;
		if(x<=2) c-= x;
		else c+=5-x;
		if(c==0) cout<<"Exact amount."<<endl;
		else if(v1>v2) cout<<"Not enough money offered."<<endl;
		else {
			vector<pair<string, int> > v;
			for(int i=0;i<9;i++) if(c>=value[i]) {
				v.push_back(make_pair(name[i], c/value[i]));
				c %= value[i];
			}
			cout<<v[0].first<<"*"<<v[0].second;
			for(int i=1;i<v.size();i++) cout<<" "<<v[i].first<<"*"<<v[i].second;
			cout<<endl;
		}
	}
	return 0;
}

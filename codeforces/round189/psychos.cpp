#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int s[100010], l[100010], r[100010], vis[100010];

int main() {
	int n, i, j, ans=0;
	cin>>n;
	vector<int> todel;
	for(i=1;i<=n;i++) {
		cin>>s[i];
		l[i] = i-1;
		r[i] = i+1;
		if(s[i]<s[i-1]) todel.push_back(i);
	}
	while(todel.size()) {
		vector<int> aux;
		for(i=0;i<todel.size();i++) {
			j = todel[i];
			vis[j]=1;
			r[l[j]] = r[j];
			l[r[j]] = l[j];
		}
		for(i=0;i<todel.size();i++) {
			j=todel[i];
			if(r[j] <= n && l[j]>=1 && s[r[j]]<s[l[j]] && !vis[r[j]]) aux.push_back(r[j]);
		}
		todel = aux;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}

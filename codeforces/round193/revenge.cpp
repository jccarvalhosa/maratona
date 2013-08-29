#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n,p,k,m,a,b;
vector<pair<int,int> > s;
vector<pair<int,pair<int,int> > > v;
int main() {
    cin>>n>>p>>k;
    for(int i=1;i<=n;i++) {
        cin>>a>>b;
        v.push_back(make_pair(-b,make_pair(a, i)));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-p+k;i++) s.push_back(make_pair(-v[i].second.first, i));
    sort(s.begin(),s.end());
    for(int i=0;i<k;i++) cout<<v[s[i].second].second.second<<" ", m=max(m, s[i].second);
    for(int i=m+1;i<m+1+p-k;i++) cout<<v[i].second.second<<" ";
	cout<<endl;
	return 0;
}

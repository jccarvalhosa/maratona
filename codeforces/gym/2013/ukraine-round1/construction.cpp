#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int v[111111];
vector<int> pos[111111];

int main() {
    int n, m;
    ll sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        pos[i%m].push_back(v[i]);
    }
    for(int i=0;i<m;i++) {
        int s = pos[i].size();
        if(s<2) continue;
        vector<ll> dp(s);
        dp[0] = 0;
        dp[1] = max(0, pos[i][0] + pos[i][1]);
        for(int j=2;j<s;j++) dp[j] = max(dp[j-1], dp[j-2] + pos[i][j] + pos[i][j-1]);
        sum += dp[s-1];
    }
    cout<<sum<<endl;
    return 0;
}

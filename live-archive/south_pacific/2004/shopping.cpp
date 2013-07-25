#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

pii v[444];

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
        sort(v, v+n);
        priority_queue<int> q;
        int t=0;
        int i=0;
        int ans=0;
        while(1) {
            if(i==n && q.empty()) break;
            while(i<n && v[i].first ==t) {
                q.push(-v[i++].second);
            }
            int delta;
            if(i==n) delta=1000000000;
            else delta = v[i].first - t;
            while(!q.empty() && delta) {
                int v = -q.top();
                q.pop();
                if(v>delta) {
                    v-=delta;
                    ans += delta * q.size();
                    q.push(-v);
                    delta=0;
                } else {
                    delta -= v;
                    ans += v * q.size();
                }
            }
            t = v[i].first;
        }
        cout<<n<<" "<<ans<<endl;
    }
    return 0;
}

#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define mp make_pair
typedef vector<int> vi;

set<vi> vis;

int dx[] = {0, 0, 1};
int dy[] = {1, 2, 2};

int go(vi v) {
    sort(v.begin(), v.end());
    queue<pair<vi, int> > q;
    q.push(mp(v, 0));
    vis.insert(v);
    while(!q.empty()) {
        int d = q.front().second;
        v = q.front().first;
        if(v[0]==0) return d;
        q.pop();
        for(int i=0;i<3;i++) {
            vi u = v;
            u[dy[i]] -= u[dx[i]];
            if(u[dy[i]]==0) return d+1;
            u[dx[i]] *= 2;
            sort(u.begin(), u.end());
            if(!vis.count(u)) {
                vis.insert(u);
                q.push(mp(u, d+1));
            }
        }
    }
}

int main() {
    int a, b, c;
    while(1) {
        vi v(3);
        cin>>v[0]>>v[1]>>v[2];
        if(v[0]+v[1]+v[2]==0) break;
        vis.clear();
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<go(v)<<endl;
    }
    return 0;
}

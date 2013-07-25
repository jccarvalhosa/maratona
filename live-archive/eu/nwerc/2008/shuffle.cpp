#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

int vis[111111];
int sum[111111];

void add(int a, int b) {
    sum[a]--;
    sum[b+1]++;
}

int main() {
    int t, m, n, h;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=0;i<n;i++) sum[i]=0;
        sum[0]=1;
        for(int i=0;i<=n;i++) vis[i]=-1;
        for(int i=0;i<m;i++) {
            cin >> h;
            if(vis[h]==-1) vis[h]=i;
            else {
                int ini=(vis[h])%n;
                int fim=i%n;
                if(i-vis[h]>=n) {
                    vis[h]=i;
                    continue;
                }
                vis[h]=i;
                if(ini<fim) {
                    if(ini>0) add(0, ini-1);
                    add(fim, n-1);
                }
                else {
                    add(fim, ini-1);
                }
            }
        }
        int ret=0;
        if(sum[0]>0) ret++;
        for(int i=1;i<n;i++) {
            sum[i] += sum[i-1];
            if(sum[i]>0) ret++;
        }
        cout << ret << endl;
    }
    return 0;
}

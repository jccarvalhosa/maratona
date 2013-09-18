#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define INF 1000000000
#define mp make_pair
typedef pair<int, int> pii;

int L, H, W, N, S;
string tab[11][111];
int dist[11][111][111];

int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};

void bfs() {
    for(int i=0;i<L;i++) for(int j=0;j<H;j++) for(int k=0;k<W;k++) dist[i][j][k]=INF;
    int a, b, h, d;
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(tab[0][i][j]=='S') a=i, b=j;
    queue<pair<pii, pii> > q;
    // (dist - z) - (x, y)
    q.push(mp(mp(0, 0), mp(a, b)));
    dist[0][a][b]=0;
    while(!q.empty()) {
        d = q.front().first.first;
        h = q.front().first.second;
        a = q.front().second.first;
        b = q.front().second.second;
        q.pop();
        for(int i=0;i<6;i++) {
            int nh = h+dz[i];
            int na = a+dx[i];
            int nb = b+dy[i];
            if(nh<0 || nh>=L) continue;
            if(na<0 || na>=H) continue;
            if(nb<0 || nb>=W) continue;
            if(tab[nh][na][nb] == 'X') continue;
            if(dz[i] == 1 && tab[h][a][b] != 'U') continue;
            if(dz[i] == -1 && tab[h][a][b] != 'D') continue;
            if(dist[nh][na][nb] == INF) {
                q.push(mp(mp(d+1, nh), mp(na, nb)));
                dist[nh][na][nb]=d+1;
            }
        }
    }
}

int dp[111][11111];

int main() {
    int T;
    cin>>T;
    vector<pii> v;
    while(T--) {
        cin>>L>>H>>W>>N>>S;
        for(int i=0;i<L;i++) for(int j=0;j<H;j++) cin>>tab[i][j];
        bfs();
        v.clear();
        for(int i=0;i<N;i++) {
            int h, a, b, p;
            cin>>h>>a>>b>>p;
            h--; a--; b--;
            if(dist[h][a][b] == INF) continue;
            v.push_back(pii(p, 3*dist[h][a][b]));
        }
        for(int i=0;i<=v.size();i++) dp[i][0]=0;
        for(int i=0;i<=S;i++) dp[0][i]=0;
        for(int i=1; i<=v.size(); i++) {
            int val=v[i-1].first;
            int w=v[i-1].second;
            for(int j=1; j<=S; j++) {
                dp[i][j]=dp[i-1][j];
                if(j>=w && dp[i-1][j-w]+val>dp[i][j]) dp[i][j]=dp[i-1][j-w]+val;
            }
        }
        cout << dp[v.size()][S] << endl;
    }
    return 0;
}

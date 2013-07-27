#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char s[55][55];
int v[55555];
int vis[55];

int main()
{
    int n, c, l, l2, r, r2, y;
    cin >> n;
    for(int i=1;i<=n;i++) {
        scanf(" %[^\n] %d.%d %d.%d", s[i], &l, &l2, &r, &r2);
        l = l*10+l2;
        r = r*10+r2;
        for(int j=l;j<=r;j++) v[j] = i;
    }
    cin >> c;
    for(int i=0;i<c;i++) {
        cin >> y;
        cout << "Galactic year " << y << ": ";
        int f=0;
        memset(vis,0,sizeof(vis));
        for(int j=y*10;j<=(y+1)*10-1;j++) {
            if(v[j] && !vis[v[j]]) {
                if(!f) cout << s[v[j]];
                else cout << ", " << s[v[j]];
                f = 1;
                vis[v[j]] = 1;
            }
        }
        if(!f) cout << "None";
        cout << endl;
    }
    return 0;
}

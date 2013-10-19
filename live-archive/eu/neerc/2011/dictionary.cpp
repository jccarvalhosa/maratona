#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Trie {
    int n, g[444444][26];
    void init() {
        n = 1;
        for(int i=0;i<26;i++) g[0][i] = -1;
    }
    void add(string s) {
        int e = 0;
        for(int i=0;i<s.size();i++) {
            int next = s[i]-'a';
            if(g[e][next] == -1) {
                g[e][next] = n;
                for(int j=0;j<26;j++) g[n][j] = -1;
                n++;
            }
            e = g[e][next];
        }
    }
};

Trie pref, suf;
int sufc[26];

void sufcnt(int e) {
    for(int i=0;i<26;i++) if(suf.g[e][i] != -1) {
		if(e) sufc[i]++;
		sufcnt(suf.g[e][i]);
    }
}

ll dfs(int e) {
    ll ret = 0;
    for(int i=0;i<26;i++) if(pref.g[e][i] != -1) {
		if(e) ret += sufc[i];
		ret += dfs(pref.g[e][i]);
    }
    return ret;
}

int main() {
    int n;
    string s;
    ll ans;
    while(scanf("%d", &n) != EOF) {
        pref.init();
        suf.init();
        memset(sufc,0,sizeof(sufc));
		int vis[26]={0};
        for(int i=0;i<n;i++) {
            cin >> s;
			if(s.size()==1) vis[s[0]-'a']=1;
            pref.add(s);
            reverse(s.begin(),s.end());
            suf.add(s);
        }
        sufcnt(0);
        ans = 1ll*(pref.n-1)*(suf.n-1);
        ans -= dfs(0);
		for(int i=0;i<26;i++) if(vis[i]) ans++;
        cout << ans << endl;
    }
    return 0;
}

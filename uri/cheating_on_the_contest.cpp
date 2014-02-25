#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

char s[555];
int S;

const int N=1000;
vector<int> adj[N][3];
int vis[N][55];
int n, t, f[N];

int get() {
	adj[n][0].clear();
	adj[n][1].clear();
	adj[n][2].clear();
	return n++;
}

void build(int pa, int pb, int sa, int sb) {
	if(pa==pb) {
		adj[sa][s[pa]=='b'].push_back(sb);
		return;
	}
	int c=0;
	for(int i=pa;i<=pb;i++) {
		if(s[i]=='(') c++;
		else if(s[i]==')') c--;
		else if(!c) {
			if(s[i]=='.') {
				int s1 = get();
				build(pa, i-1, sa, s1);
				build(i+1, pb, s1, sb);
				return;
			}
			if(s[i]=='|') {
				int s1 = get(), s2 = get();
				build(pa, i-1, s1, sb);
				build(i+1, pb, s2, sb);
				adj[sa][2].push_back(s1);
				adj[sa][2].push_back(s2);
				return;
			}
			if(s[i]=='*') {
				int s1 = get();
				build(pa, i-1, sa, s1);
				adj[s1][2].push_back(sa);
				adj[sa][2].push_back(sb);
				return;
			}
		}
	}
	build(pa+1, pb-1, sa, sb);
}

int match(int st, int pos) {
	vis[st][pos]=t;
	if(pos==S && st==1) return 1;
	for(int i=0;i<adj[st][2].size();i++) {
		int nst = adj[st][2][i];
		if(vis[nst][pos]!=t && match(nst, pos)) return 1; 
	}
	if(pos<S) for(int i=0;i<adj[st][s[pos]=='b'].size();i++) {
		int nst = adj[st][s[pos]=='b'][i];
		if(vis[nst][pos+1]!=t && match(nst, pos+1)) return 1;
	}
	return 0;
}

int main() {
	while(scanf("%s", s) != EOF) {
		n=0;
		S = strlen(s);
		get(); get();
		build(0, S-1, 0, 1);
		int q;
		scanf("%d", &q);
		gets(s);
		while(q--) {
			gets(s);
			S = strlen(s);
			t++;
			printf("%c\n", match(0, 0) ? 'Y' : 'N');
		}
		printf("\n");
	}
	return 0;
}

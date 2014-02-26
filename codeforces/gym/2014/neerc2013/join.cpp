#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int INF=1e9;
char s[222], m[222];
char *pt;
map<string, int> best;
int dp[55555], pi[55555];

int main() {
	freopen("join.in", "r", stdin);
	freopen("join.out", "w", stdout);
	int n, i, v;
	scanf("%d", &n);
	for(i=0; i<n; i++) dp[i]=1, pi[i]=-1;
	for(i=0; i<n; i++) {
		getchar();
		scanf("%s", s);
		s[strlen(s)-1]='\0';
		getchar();
		scanf("%[^\n]", m);
		pt=strtok(m, " ");
		while(pt!=NULL) {
			if(pt[0]=='@' && strcmp(s, pt) && best.count(pt)) {
				v=best[pt];
				if(1+dp[v]>dp[i]) dp[i]=1+dp[v], pi[i]=v;
			}
			pt = strtok(NULL, " ");
		}
		if(!best.count(s)) best[s]=i;
		else if(dp[i]>dp[best[s]]) best[s]=i;
	}
	int ans=-1, ind;
	vector<int> sol;
	for(i=0; i<n; i++) if(dp[i]>ans) ans=dp[i], ind=i;
	printf("%d\n", ans);
	for(i=ind; i!=-1; i=pi[i]) sol.push_back(i+1);
	reverse(sol.begin(), sol.end());
	printf("%d", sol[0]);
	for(i=1; i<sol.size(); i++) printf(" %d", sol[i]);
	printf("\n");
	return 0;
}

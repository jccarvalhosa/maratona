#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, p, nc, h;

const int N=1e6+10;
int c[N], m[N], w[N], sc[N], sm[N];

int valid(int a, int b) {
	if(a==-1 || a==h) return 1;

	sc[c[b]]--;
	sc[m[0]]++;

	int sa = min(sc[a] + sm[a], n-1);
	if(m[p-1] == a) sa++;

	int sh = sc[h];
	if(sh >= 1) sh--;
	sh = max(0, sh - (p-2 - sm[h]));
	if(m[p-1] == h) sh++;

	int valid = sh > sa;
	if(p==1) valid = sc[h] > sc[a];

	sc[m[0]]--;
	sc[c[b]]++;

	return valid;
}

int main() {
	freopen("kabaleo.in", "r", stdin);
	freopen("kabaleo.out", "w", stdout);
	cin>>n>>p>>nc>>h;h--;
	for(int i=0;i<n;i++) {
		scanf("%d", &c[i]); c[i]--;
		sc[c[i]]++;
	}
	for(int i=0;i<p;i++) {
		scanf("%d", &m[i]); m[i]--;
		if(i!=0 && i!=p-1) sm[m[i]]++;
	}
	int cor[] = {m[p-1], m[0], 0, 0};
	int best1, best2, val=0;
	priority_queue<pii> q;
	q.push(pii(-1, -1));
	q.push(pii(-1, -1));
	for(int i=0;i<nc;i++) if(i!=h && i!=m[p-1] && i!=m[0]) q.push(pii(sm[i] + sc[i], i));
	cor[2] = q.top().second;
	q.pop();
	cor[3] = q.top().second;
	for(int i=0;i<n;i++) w[i] = valid(cor[0], i) && valid(cor[1], i) && valid(cor[2], i) && valid(cor[3], i);
	int sum=0;
	for(int i=0;i<n;i++) if(w[i]) sum++;
	cout<<sum<<endl;
	for(int i=0;i<n;i++) if(w[i]) printf("%d\n", i+1);
	return 0;
}

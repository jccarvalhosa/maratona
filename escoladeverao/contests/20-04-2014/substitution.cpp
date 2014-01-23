#include <cstdio>
#include <cstring>
typedef long long ll;

const int N = (int)2e5 + 10;
const ll C = 1234567;
const ll M = (ll)1e9 + 7;

char a[N], b[N];
ll h[N], pot[N];
int A, B, na, nb;

ll hash(int i, int f) { return ((((h[f+1] - h[i])*pot[B-i]) % M) + M) % M; }

void print(int a, int t) {
	if(t==0) printf("-");
	else {
		for(int i=a;i<a+t;i++) printf("%c", b[i]);
	}
	printf("\n");
}

int solve(ll ta, ll tb) {
	if(ta*na + tb*nb != B) return 0;
	int pa=-1, pb=-1, p=0;
	for(int i=0;i<A;i++) {
		if(a[i]=='a') {
			if(pa == -1) pa = p;
			else if(hash(pa, pa+ta-1) != hash(p, p+ta-1)) {
				return 0;
			}
			p += ta;
		}
		if(a[i]=='b') {
			if(pb == -1) pb = p;
			else if(hash(pb, pb+tb-1) != hash(p, p+tb-1)) return 0;
			p += tb;
		}
	}
	print(pa, ta);
	print(pb, tb);
	return 1;
}

int main() {
	pot[0] = 1;
	for(int i=1;i<N;i++) pot[i] = (C*pot[i-1])%M;
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", a);
		scanf("%s", b);
		A = strlen(a);
		B = strlen(b);
		for(int i=1;i<=B;i++) h[i] = (h[i-1] + pot[i-1]*b[i-1])%M;
		na = nb = 0;
		for(int i=0;i<A;i++) {
			if(a[i] == 'a') na++;
			if(a[i] == 'b') nb++;
		}
		if(na == 0) { if(!solve(0, B/nb)) printf("NIE\n"); }
		else if(nb == 0) { if(!solve(B/na, 0)) printf("NIE\n"); }
		else {
			int valid=0;
			for(ll ta=1;ta<=B;ta++) {
				ll tb = (B - ta*na)/nb;
				if(tb <= 0) continue;
				if(solve(ta, tb)) {
					valid=1;
					break;
				}
			}
			if(!valid) printf("NIE\n");
		}
	}
	return 0;
}

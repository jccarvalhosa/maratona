#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int mod(ll a) { return a > 0 ? a : -a; }

int T, n, x;

struct S { 
	int i, f, d;
	ll vi, vf;
	S(int i=1, int f=T, ll vi=1, ll vf=T, int d=1): i(i), f(f), vi(vi), vf(vf), d(d) {}
};


ll val(int ind, S s) { return s.vi + s.d*(ind-s.i); }
ll pasum(ll a, ll b) { return (a+b)*(mod(b-a)+1)/2; }

S s[1000000];
int aux[1000000];

bool mycmp(int a, int b) { return s[a].i > s[b].i; }

int main() {
	int M, i, a, b;
	char c;
	scanf("%d%d", &T, &M);
	s[0] = S();
	n=1;
	while(M--) {
		scanf(" %c %d %d", &c, &a, &b);
		if(a > b) swap(a, b);
		if(c == 'I') {
			x = 0;
			for(i=0;i<n;i++) if(a <= s[i].f && b >= s[i].i) {
				if(s[i].i < a) {
					s[n++] = S(s[i].i, a-1, s[i].vi, val(a-1, s[i]), s[i].d);
					s[i].vi = val(a, s[i]);
					s[i].i = a;
				}
				if(s[i].f > b) {
					s[n++] = S(b+1, s[i].f, val(b+1, s[i]), s[i].vf, s[i].d);
					s[i].vf = val(b, s[i]);
					s[i].f = b;
				}
				s[i].d *= -1;
				swap(s[i].vi, s[i].vf);
				aux[x++] = i; 
			}
			sort(aux, aux+x, mycmp);
			s[aux[0]].i = s[aux[x-1]].i;
			s[aux[0]].f = s[aux[0]].i + mod(s[aux[0]].vi - s[aux[0]].vf);
			for(i=1;i<x;i++) {
				s[aux[i]].i = s[aux[i-1]].f + 1;
				s[aux[i]].f = s[aux[i]].i + mod(s[aux[i]].vi - s[aux[i]].vf);
			}
		}
		if(c == 'S') {
			ll sum=0;
			for(i=0;i<n;i++) if(a <= s[i].f && b >= s[i].i) {
				ll aux = pasum(val(max(a, s[i].i), s[i]), val(min(b, s[i].f), s[i]));
				sum += aux;
			}
			printf("%lld\n", sum);
		}
	}
	return 0;
}

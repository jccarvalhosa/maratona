#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

const int N=1e4;
int n;
struct pt {
    ll x, y;

    pt(ll x=0, ll y=0): x(x), y(y) {}

    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(ll c) { return pt(x*c, y*c); }
    pt operator /(ll c) { return pt(x/c, y/c); }
    ll operator *(pt p) { return x*p.x + y*p.y; }
    ll operator %(pt p) { return x*p.y - y*p.x; }
    int cmp(pt p) const {
		if(x < p.x) return -1;
		if(x > p.x) return 1;
		if(y < p.y) return -1;
		if(y > p.y) return 1;
		return 0;
    }
    bool operator ==(pt p) { return cmp(p) == 0; }
    bool operator !=(pt p) { return cmp(p) != 0; }
    bool operator <(const pt &p)const { return cmp(p) < 0; }
    bool operator >(const pt &p)const { return cmp(p) > 0; }
    bool operator <=(const pt &p)const { return cmp(p) <= 0; }
    bool operator >=(const pt &p)const { return cmp(p) >= 0; }
    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }
    
    ll prod(pt p, pt q) { return (*this-p) % (q-p); }
    //true se o ponto em questao esta entre os pontos p e q
    bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
    //true se o ponto esta a esquerda do segmento pq
    bool left(pt p, pt q) { return prod(p, q) < 0; }
    //true se o ponto esta a direita do segmento pq
    bool right(pt p, pt q) { return prod(p, q) > 0; }
};

pt pivot;

bool radial_lt(pt p, pt q) {
    pt P = p - pivot, Q = q - pivot;
    ll R = P % Q;
    if(R) return R > 0;
    return P*P > Q*Q;
}

typedef vector<pt> polygon;

//GRAHAM SCAN
polygon convex_hull(vector<pt> T) {
    int i, j=0, k, n=T.size(); polygon U(n);
    pivot = *min_element(all(T));
    sort(all(T), radial_lt);
    for(k=n-2; k>=0 && T[0].prod(T[k], T[n-1]) == 0; k--) ;
    reverse((k+1) + all(T));
    for(i=0;i<n;i++) {
        while(j>1 && T[i].prod(U[j-1], U[j-2]) <= 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + all(U));
    return U;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		polygon p(n);
		for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
		cout << "Case #"<<t<<":"<<endl; 
		for(int i=0;i<n;i++) {
			int sz = 1;
			for(int j=0;j<n;j++) if(i != j) {
				int l=0, r=0;
				for(int k=0;k<n;k++) {
					if(p[k].prod(p[i], p[j]) <= 0) l++;
					if(p[k].prod(p[i], p[j]) >= 0) r++;
				}
				sz = max(sz, max(l, r));
				if(sz == n) break;
			}
			cout << n - sz << endl;
		}
	}
	return 0;
}

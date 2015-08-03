#include <iostream>
#include <string>
using namespace std;

long long x;
int l;
char s[111111];

struct number {
	char val;
	int sign;
	number(char val='1', int sign=1) : val(val), sign(sign) {}
	number(int sign) : val('1'), sign(sign) {}
	number operator*(int s) { return number(val, sign*s); }
	number operator*(number n) { 
		int s = sign * n.sign;
		if(val == '1') return number(n.val, s);
		if(n.val == '1') return number(val, s);
		if(val == n.val) return number('1', -s);
		if(val == 'i' && n.val == 'j') return number('k', s);
		if(val == 'i' && n.val == 'k') return number('j', -s);
		if(val == 'j' && n.val == 'k') return number('i', s);
		if(val == 'j' && n.val == 'i') return number('k', -s);
		if(val == 'k' && n.val == 'i') return number('j', s);
		if(val == 'k' && n.val == 'j') return number('i', -s);
		throw;
	}
};

int solve() {
	number prod;
	for(int i=0;i<l;i++) prod = prod * number(s[i]);
	number aux = prod;
	for(int i=0;i<(x-1)%4;i++) prod = aux * prod;
	if(prod.val != '1' || prod.sign != -1) return 0;
	int bp=-1, bv=4;
	prod = number();
	for(int i=0;i<l;i++) {
		prod = prod * number(s[i]);
		number copy = prod;
		aux = number(s[i]) *number(s[i]) * number(s[i]) * aux * number(s[i]);
		for(int t=0;t<4;t++) {
			if(bv <= t) continue;
			if(copy.val == 'i' && copy.sign == 1) {
				bp = i;
				bv = t;
			}
			copy = copy * aux;
		}
	}
	int ep=-1, ev=4;
	prod = number();
	for(int i=l-1;i>=0;i--) {
		prod = number(s[i]) * prod;
		number copy = prod;
		aux = number(s[i]) * aux * number(s[i]) * number(s[i]) *number(s[i]);
		for(int t=0;t<4;t++) {
			if(ev <= t) continue;
			if(copy.val == 'k' && copy.sign == 1) {
				ep = i;
				ev = t;
			}
			copy = aux * copy;
		}
	}
	if(bp == -1 || ep == -1) return 0;
	int vmin = 1 + ev + bv;
	if(bp >= ep-1) vmin++;
	return x >= vmin;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>l>>x;
		scanf("%s", s);
		int ans = solve();
		cout << "Case #"<<t<<": "<<(ans?"YES":"NO")<<endl;
	}
	return 0;
}

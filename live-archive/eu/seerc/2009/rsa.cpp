#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
#define M 1000000000
#define MAXD 30
typedef long long ll;

struct bignum {
	int sz;
	int sign; 
	int dig[MAXD];
	
	bignum(int v=0) {
		for(int i=2;i<MAXD;i++) dig[i] = 0;
		sign = 1;
		sz = 2;
		if(v < 0) {
			sign = -1;
			v = -v;
		}
		dig[0] = v % M;
		dig[1] = v / M;
		if(dig[1] == 0) sz--;
	}

	bignum(char *c) {
		int i,q,k,v,pw;
		for(i=0;i<MAXD;i++) dig[i] = 0;
		k = strlen(c);
		if(c[0] == '-') sign = -1;
		else sign = 1;

		sz = 0;
		v = 0;
		q = 0;
		pw = 1;
		for(i=k-1;i>=0;i--){
			if(c[i] == '-') break;
			v += pw*(c[i] - '0');
			q++;
			pw *= 10;
			if(q >= 9){
				pw = 1;
				q = 0;
				dig[sz++] = v;
				v = 0;    
			}    
		}

		dig[sz++] = v;
		this->justify();
	}
	
	void justify() {
		int i;
		for(i=sz-1;i>=0;i--) if(dig[i]) break;
		sz = 1+i;
		if(!sz) sz=1;
		if(sz == 1 && dig[0] == 0) sign = 1;
	}
	
	void shift(int k){
		if(sz == 1 && dig[0] == 0) return ;
		for(int i=sz-1;i>=0;i--) dig[i+k] = dig[i];
		for(int i=k-1;i>=0;i--) dig[i] = 0;
		sz += k;
	}
	
	void negate() { if(*this != 0) this->sign = -this->sign; }
	
    friend ostream& operator <<(ostream& o, bignum b) { 
		if(b.sign < 0) o<<"-";
		o<<b.dig[b.sz-1];
		for(int i=b.sz-2;i>=0;i--) o<<setfill('0')<<setw(9)<<b.dig[i];
		return o;
	}
	
	int cmp(bignum b) const {
		if(sign > 0 && b.sign < 0) return 1;
		if(sign < 0 && b.sign > 0) return -1;
		if(sz > b.sz) return sign;
		if(sz < b.sz) return -sign;
		for(int i=sz-1;i>=0;i--){
			if(dig[i] > b.dig[i]) return sign;
			if(dig[i] < b.dig[i]) return -sign;    
		}
		return 0;
	}
	
	bool operator<(const bignum &b) { return (cmp(b) < 0); }
	bool operator<=(const bignum &b) { return (cmp(b) <= 0); }
	bool operator>(const bignum &b) { return (cmp(b) > 0); }
	bool operator>=(const bignum &b) { return (cmp(b) >= 0); }
	bool operator==(const bignum &b) { return (cmp(b) == 0); }
	bool operator!=(const bignum &b) { return (cmp(b) != 0); }
	
	bignum operator+(bignum b) {
		if(sign != b.sign) {
			if(sign == -1) {
				sign = 1;
				bignum ret = b - *this;
				sign = -1;
				return ret;
			}
			b.sign = 1;
			return *this - b;
		}
		bignum ret;
		ret.sign = sign;
		ret.sz = 1 + max(sz,b.sz);
		int c = 0;
		for(int i=0;i<ret.sz;i++) {
			ret.dig[i] = c + dig[i] + b.dig[i];
			c = 0;
			if(ret.dig[i] >= M) {
				c = 1;
				ret.dig[i] -= M;
			}
		}
		ret.justify();
		return ret;   
	}
	
	bignum operator-(bignum b) {
		bignum ret;
		if(sign < 0 || b.sign < 0) {
			b.sign = -b.sign;
			return *this+b;
		}
		if(*this<b){
			ret = b-*this;
			ret.sign = -1;
			return ret;    
		}
		ret.sign = 1;
		ret.sz = max(sz,b.sz);
		int brw = 0;
		for(int i=0;i<ret.sz;i++) {
			int k = dig[i] - b.dig[i] - brw;
			if(k>=0) brw=0;
			else {
				k += M;
				brw = 1;
			}
			ret.dig[i] = k;
		}
		ret.justify();
		return ret;
	}
	
	bignum operator*(bignum b){
		bignum ret, buf;
		for(int i=0;i<b.sz;i++){
			buf.sz = 1+sz;
			int c=0;
			for(int j=0;j<buf.sz;j++){
				long long hlp = 1ll*b.dig[i]*dig[j] + c;
				c = hlp/M;
				buf.dig[j] = hlp%M;
			}
			buf.shift(i);
			ret = ret + buf;
		}
		ret.sign = sign*b.sign;
		ret.justify();
		return ret;    
	}
	
	bignum operator*(int v) {
		bignum ret;
		ret.sz = 1+sz;
		int c=0;
		for(int i=0;i<ret.sz;i++) {
			long long hlp = 1ll*v*dig[i] + c;
			c = hlp/M;
			ret.dig[i] = hlp%M;
		}
		ret.justify();
		return ret;        
	}
	
	bignum operator/(bignum b) {
		bignum ret, row;
		ret.sign = sign*b.sign;
		int as = sign;
		int bs = b.sign;
		sign = 1;
		b.sign = -1;
		ret.sz = sz;
		int i, x, y, z;
		for(i=sz-1;i>=0;i--) {
			row.shift(1);
			row.dig[0] = dig[i];
			x = 0;
			y = M-1;
			while(1){
				z = (1+x+y)/2;
				if(x == y) break;
				if(b*z <= row) x = z;        
				else y = z-1;    
			}
			ret.dig[i] = z;
			row = b*z - row;
			row.negate();
		}
		sign = as;
		b.sign = bs;
		ret.justify();
		return ret;
	}
};

bignum sqrt(bignum b) {
	bignum m, i=0, f=b;
	while(1) {
		m = (i+f)/2;
		if(m*m>b) {
			if((m-1)*(m-1)<=b) return m-1;
			f=m-1;
		} else {
			if((m+1)*(m+1)>b) return m;
			i=m+1;
		}
	}
}

char c[10000];
int k;
bignum n, p, q;

int find(bignum x, bignum delta) {
	p = (delta-x)/(2*k);
	q = p*k+x;
	if(p>1 && q>1 && p*q == n) return 1;
	q = p*k-x;
	if(p>1 && q>1 && p*q == n) return 1;
	p = (delta+x)/(2*k);
	q = p*k+x;
	if(p>1 && q>1 && p*q == n) return 1;
	q = p*k-x;
	if(p>1 && q>1 && p*q == n) return 1;
	return 0;
}

int main() {
	while(scanf("%s %d", c, &k) != EOF) {
		n = bignum(c);
		if(n.sz == 1) {
			int num = n.dig[0];
			for(int i=2;i<=num;i++) if(num % i == 0) {
				cout<<i<<" * "<<num/i<<endl;
				break;
			}
		}
		else {
			bignum v = n * (4*k);
			bignum r = sqrt(v);
			for(int i=0;;i++) {
				bignum aux = (r+i)*(r+i) - v;
				if(aux<0) continue;
				bignum x = sqrt(aux);
				if(x*x == aux) {
					bignum delta = sqrt(x*x + v);
					if(find(x, delta)) {
						if(p>q) swap(p, q);
						cout<<p<<" * "<<q<<endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}

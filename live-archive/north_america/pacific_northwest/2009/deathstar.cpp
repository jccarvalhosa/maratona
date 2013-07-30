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
#define MAXD 7
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
		dig[0] = v % 1000000000;
		dig[1] = v / 1000000000;
		if(dig[1] == 0) sz--;
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
				return b - *this;
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
			if(ret.dig[i] >= 1000000000) {
				c = 1;
				ret.dig[i] -= 1000000000;
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
				k += 1000000000;
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
				c = hlp/1000000000;
				buf.dig[j] = hlp%1000000000;
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
			c = hlp/1000000000;
			ret.dig[i] = hlp%1000000000;
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
			y = 1000000000-1;
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

//////////////MY CODE///////////////////

int n, m, N;
int conv(int i, int j) { return m*i+j; }
bignum p[66];

struct matrix {
	bignum v[64][64];
	matrix operator*(matrix a) {
		matrix ans;
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) for(int k=0;k<N;k++) {
			ans.v[i][j] = (ans.v[i][j] + (v[i][k] * a.v[k][j]));
		}
		return ans;
	}
};

bignum tr(matrix a) {
	bignum ret=0;
	for(int i=0;i<N;i++) ret = ret + a.v[i][i];
	return ret;
}

void laverrier_faddev(matrix a) {
	matrix aux=a;
	for(int i=1;i<=N;i++) {
		p[i] = tr(aux) / i;
		matrix b = aux;
		for(int j=0;j<N;j++) b.v[j][j] = b.v[j][j] - p[i];
		aux = b * a;
	}
}

int main() {
	string v[8];
	int adj[64][64];
	int deg[64];
	int dx[] = {1, 0, 0, -1};
	int dy[] = {0, 1, -1, 0};
	while(1) {
		cin>>n>>m;
		if(n+m==0) break;
		N = n*m;
		for(int i=0;i<n;i++) cin>>v[i];
		if(N==1) {
			cout<<1<<endl;
			continue;
		}
		memset(adj, 0, sizeof(adj));
		memset(deg, 0, sizeof(deg));
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
			if(v[i][j]=='#') continue;
			int a = conv(i, j);
			for(int k=0;k<4;k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if(ni<0||nj<0||ni>=n||nj>=m||v[ni][nj]=='#') continue;
				int b = conv(ni, nj);
				adj[a][b] = 1;
				deg[a]++;
			}
		}
		matrix a;
		for(int i=0;i<N;i++) a.v[i][i] = deg[i];
		for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) if(adj[i][j]) a.v[i][j] = a.v[j][i] = -1;
		laverrier_faddev(a);
		for(int i=N;i>=1;i--) if(p[i] != 0) {
			bignum ans = p[i] / (i+1);
			ans.sign = 1;
			cout<<ans.dig[0]<<endl;
			break;
		}
	}
	return 0;
}

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <complex>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef complex < double> cd;

int key(int k,int p) {
	p = 1 << (p-1);
	int r = 0;
	while(k) {
		if(k & 1) r += p;
		p >>= 1;
		k >>= 1;
	}
	return r;
}

void fft(vector<cd> &A,int s) {
	int p, n=A.size();
	for(p=0;n>1;p++) n >>= 1;
	n = 1 << p;
	vector<cd> aa(A);
	for(int i=0;i<n;i++) A[key(i,p)] = aa[i];
	cd w,wn,t,u;
	int m, r;
	for(int i=1;i<=p;i++) {
		m = 1 << i;
		r = m >> 1;
		wn = cd(cos(s*2*M_PI/m), sin(s*2*M_PI/m));
		w = 1.0;
		for(int j=0;j<r;j++) {
			for(int k = j; k < n ; k += m) {
				t = w * A[k + r];
				u = A[k];
				A[k] = u + t;
				A[k + r] = u - t;
			}
			w = w * wn;
		}
	}
	if(s==-1) for(int i = 0;i<n;++i) A[i] /= n;
}

vector<cd> multiply(vector<cd> &P, vector<cd> &Q){
	int n = P.size()+Q.size();
	int p=1;
	while(p<n) p*=2;
	n = p;
	P.resize(n,0);
	Q.resize(n,0);
	fft(P,1);
	fft(Q,1);
	vector<cd> R;
	for(int i=0;i<n;i++) R.push_back(P[i]*Q[i]);
	fft(R,-1);
	return R;
}

const int N = 100100;

vector <int> v;
ll cnt[N];

ll solve(){
	int maxVal = 0;
	for(int i=0;i<v.size();i++) maxVal = max(maxVal, v[i]);
	vector<cd> P(2 * maxVal+2),Q(2 * maxVal+2);
	for(int i=0;i<P.size();i++) P[i] = Q[i] = 0.0;
	for(int i = 0; i < v.size(); i++) {
		P[v[i]] += 1.0;
		Q[maxVal - v[i]] += 1.0;
	}
	vector <cd> ans = multiply(P,Q);
	ll c = 0;
	for(int i=maxVal+1;i<=2*maxVal;i++)	if(real(ans[i]) > 0.5) c++;
	for(int i = 0; i <= maxVal; i++) cnt[i] = 0;
	bool found = false;
	for(int i = 0; i < v.size(); i++) {
		cnt[v[i]]++;
		if(cnt[v[i]] > 1) found = true;
		if(found) break;
	}      
	if(found) c++;
	return c;
}

int main(){
	int n;
	cin >> n;
	v.resize(n);
	for(int i=0;i<n;i++) cin >> v[i];
	cout << solve() << endl;
	return 0;
}

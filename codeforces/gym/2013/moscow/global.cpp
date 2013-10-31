#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef map<ll, ll> M;
typedef map<ll, ll>::iterator MIT;
ll mod(ll a) { return a>0 ? a : -a; }

M sell, buy, sold, bought;
ll sum=0;

void remove(ll& d , ll& v, M& m) {
	MIT it = m.find(v);
	if(it==m.end()) return;
	ll x = min(d, it->second);
	d -= x;
	it->second -= x;
	if(!it->second) m.erase(it);
}

void transfer(ll& d , ll& v, M& m, MIT& it, M& n) {
	ll x = min(d, it->second);
	sum -= x * mod(v - it->first);
	n[it->first] += x;
	d -= x;
	it->second -= x;
	if(!it->second) m.erase(it);
}

int trade(M& a, MIT& ita, M& b, MIT& itb, M& A, M& B) {
	if(ita->first - itb->first >= 0) return 0;
	ll x = min(ita->second, itb->second);
	sum += x*(itb->first - ita->first);
	A[ita->first] += x;
	B[itb->first] += x;
	ita->second -= x;
	itb->second -= x;
	if(!ita->second) a.erase(ita);
	if(!itb->second) b.erase(itb);
	return 1;
}

int main() {
	while(1) {
		string s;
		cin>>s;
		if(s=="end") return 0;
		ll d, v;
		cin>>d>>v;
		if(s=="buy") {
			if(d > 0) buy[v] += d;
			if(d < 0) {
				d *= -1;
				remove(d, v, buy);
				bought[v] -= d;
				while(d) transfer(d, v, sold, --sold.end(), sell);
			}
		}
		if(s=="sell") {
			if(d > 0) sell[v] += d;
			if(d < 0) {
				d *= -1;
				remove(d, v, sell);
				sold[v] -= d;
				while(d) transfer(d, v, bought, --++bought.begin(), buy);
			}
		}
		while(buy.size() && bought.size()) if(!trade(bought, --++bought.begin(), buy, --buy.end(), buy, bought)) break;
		while(sell.size() && sold.size()) if(!trade(sell, --++sell.begin(), sold, --sold.end(), sold, sell)) break;
		while(sell.size() && buy.size()) if(!trade(sell, --++sell.begin(), buy, --buy.end(), sold, bought)) break;
		cout << sum << endl;
	}
}

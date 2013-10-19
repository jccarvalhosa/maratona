#include <algorithm>
#include <string>
#include <climits>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
typedef unsigned long long ull;

char num[222], sa[222], sb[222], max_num[222];
ull pot[20];

struct pref {
	ull val, inv;
	int len;	
	bool zero, overflow;
	pref(int l) {
		len = l;
		zero = (num[0]=='0');
		overflow = false;
		if(l == 20) for(int i=0;i<l;i++) {
			if(num[l-i-1] > max_num[i]) { overflow=true; break; }
			if(num[l-i-1] < max_num[i]) break;
		}
		val = inv = 0;
		for(int i=0;i<l;i++) val += pot[i] * (num[l-i-1]-'0');
		for(int i=0;i<l;i++) inv += pot[i] * (num[i]-'0');
	}
};

int len, lena, lenb;
vector<pref> v;

void go(int pos, bool ga, bool lb) {
	if(pos==len || (ga && lb)) v.push_back(pref(pos));
	else for(char c='0';c<='9';c++) {
		if(!ga && c < sa[pos]) continue;
		if(!lb && c > sb[pos]) continue;
		num[pos] = c;
		go(pos+1, ga || (c > sa[pos]), lb || (c < sb[pos]));
	}
}

bool match(pref& p1, pref& p2) {
	if(p1.len+p2.len<=len) return true;	
	int d=p1.len+p2.len-len;
	if(d==20) return p1.val==p2.inv;
	return (p1.val%pot[d])==(p2.inv/pot[p2.len-d]);
}

ull count() {
	v.clear();
	go(0, false, len<lenb);
	ull ans=0;
	for(int i=0;i<v.size();i++) for(int j=0;j<v.size();j++)	{
		if(!v[i].zero && !v[j].overflow && match(v[i],v[j])) ans+=pot[max(0,len-v[i].len-v[j].len)];
	}
	return ans;
}

ull solve(ull a, ull b) {
	pot[0]=1;
	for(int i=1;i<20;i++) pot[i]=pot[i-1]*10;
	sprintf(sa,"%llu",a);
	sprintf(sb,"%llu",b);
	lena = strlen(sa);
	lenb = strlen(sb);
	sprintf(max_num,"%llu", ULLONG_MAX);
	ull ans=0;
	for(len=lena;len<=lenb;len++) {
		ans+=count();
		sa[len]='0';
		rotate(sa, sa+len, sa+len+1);
	}
	return ans;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		ull a, b;
		cin>>a>>b;
		cout << "Case " << t << ": " << solve(a, b) << endl;
	}
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
int d[222], w[100];
char decode[33];
int nar, wid, nmax, nmin, wmax, wmin;

int is_narrow(int v) { return 2*v <= 3*nar; }

int init() {
	for(int i=0;i<32;i++) decode[i] = 'x';
	decode[1] = '0'; decode[17] = '1'; decode[9] = '2';
	decode[24] = '3'; decode[5] = '4'; decode[20] = '5';
	decode[12] = '6'; decode[3] = '7'; decode[18] = '8';
	decode[16] = '9'; decode[4] = '-'; decode[6] = '@';
	for(int i=0;i<=9;i++) w[i+'0'] = i;
	w['-'] = 10;
}

int check_distances() {
	if(nmin*105 < nmax*95) return 0;
	if(wmin*105 < wmax*95) return 0;
	if(nmin*210 < wmax*95) return 0;
	if(wmin*105 < nmax*190) return 0;
	return 1;
}

int calc_c(string code) {
	int n = code.size();
	int ret = 0;
	for(int i=1;i<=n;i++) ret += (((n-i)%10)+1)*w[code[i-1]];
	return ret%11;
}

int calc_k(string code, char c) {
	int n = code.size();
	code += c;
	int ret = 0;
	for(int i=1;i<=n+1;i++) ret += (((n-i+1)%9)+1)*w[code[i-1]];
	return ret%11;
}

string solve() {
	string code = "";
	int cur = 0;
	for(int i=0;i<n;i++) {
		if(is_narrow(d[i])) {
			nmax = max(nmax,d[i]);
			nmin = min(nmin,d[i]);
			if(i%6 == 5) {
				code += decode[cur];
				if(decode[cur] == 'x') return "bad code";
				cur = 0;
			}
		} else {
			if(i%6 == 5) return "bad code";
			else cur |= (1<<(i%6));
			wmax = max(wmax,d[i]);
			wmin = min(wmin,d[i]);
		}
	}
	code += decode[cur];
	if(!check_distances()) return "bad code";
	if(code.size() < 5) return "bad code";
	if(code[0] != '@' || code[code.size()-1] != '@') return "bad code";
	char c = code[2], k = code[1];
	code = code.substr(3,code.size()-4);
	reverse(code.begin(),code.end());
	if(calc_c(code) != w[c]) return "bad C";
	if(calc_k(code, c) != w[k]) return "bad K";
	return code;
}

int valid() {
	if(!is_narrow(d[1])) return 0;
	if(is_narrow(d[2])) return 0;
	if(is_narrow(d[3])) return 0;
	if(!is_narrow(d[4])) return 0;
	return 1;
}

int main() {
	int t=1;
	init();
	while(cin >> n && n) {
		for(int i=0;i<n;i++) cin >> d[i];
		nmax = nmin = nar = d[0];
		wmax = wmin = wid = d[2];
		printf("Case %d: ", t++);
		if((n+1)%6) cout << "bad code" << endl;
		else {
			if(valid()) reverse(d,d+n);
			cout << solve() << endl;
		}
	}
	return 0;
}

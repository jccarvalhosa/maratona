#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int U, B, uv[100][2], bv[100][2][2];
map<string, int> idb, idu, val;
string expr;
string p[501];

int conv(string s) { return s=="true"?1:0;}
int islower(char c) { return c >= 'a' && c <= 'z'; }
int isupper(char c) { return c >= 'A' && c <= 'Z'; }

int main() {
	int i, j, k, t=1, n, b, u, v1, v2;
	string s, r;
	while(cin>>U>>B && U>=0) {
		val.clear(); idb.clear(); idu.clear();
		for(i=0;i<U;i++) {
			cin>>s;
			idu[s]=i;
			for(j=0;j<2;j++) {
				cin>>s;
				uv[i][j] = conv(s);
			}
		}
		for(i=0;i<B;i++) {
			cin>>s;
			idb[s]=i;
			for(j=0;j<4;j++) {
				cin>>s;
				bv[i][j/2][j%2] = conv(s);
			}
		}
		getchar();
		getline(cin, expr);
		while(cin>>s && s != "*") {
			cin>>r;
			val[s]=conv(r);
		}
		printf("Case %d: ", t++);
		n=i=0;
		while(i<expr.size()) {
			if(islower(expr[i])) {	
				s="";
				while(i<expr.size() && islower(expr[i])) s+=expr[i++];
				p[++n] = s;
			}
			else if(isupper(expr[i])) {
				s="";
				while(i<expr.size() && isupper(expr[i])) s+=expr[i++];
				p[++n] = s;
			}
			else {
				if(expr[i] == '(') p[++n] = "(";
				if(expr[i] == ')') {
					for(j=n;j > 0 && p[j] != "(";j--) ; j++;
					if(isupper(p[j][0])) {
						u = idu[p[j]];
						s = p[j+1];
						if(!val.count(s)) v1 = -1;
						else v1 = val[s];
						if(v1 != -1) v1 = uv[u][v1];
						else if(uv[u][0] == uv[u][1]) v1 = uv[u][0];
					}
					else {
						b = idb[p[j+1]];
						s = p[j];
						r = p[j+2];
						if(!val.count(s)) v1=-1;
						else v1 = val[s];
						if(!val.count(r)) v2=-1;
						else v2 = val[r];
						if(v1 != -1 && v2 != -1) v1 = bv[b][v1][v2];
						else if(v1 != -1 && bv[b][v1][0] == bv[b][v1][1]) v1 = bv[b][v1][0]; 
						else if(v2 != -1 && bv[b][0][v2] == bv[b][1][v2]) v1 = bv[b][0][v2];
						else if(bv[b][0][0] == bv[b][0][1] && bv[b][0][0] == bv[b][1][0] && bv[b][0][0] == bv[b][1][1]) v1 = bv[b][0][0];
						else v1=-1;
					}
					val[s] = v1;
					p[j-1] = s;
					n=j-1;
				}
				i++;
			}
		}
		v1 = val[p[1]];
		if(v1 == -1) cout<<"unknown"<<endl;
		else if(v1 == 0) cout<<"false"<<endl;
		else if(v1 == 1) cout<<"true"<<endl;
	}
	return 0;
}

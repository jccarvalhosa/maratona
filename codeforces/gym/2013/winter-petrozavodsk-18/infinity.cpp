#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int M=1111111;
int N, tam, n, m, k;
int val[M], t[M];
int flag=0;

int add(int x, int v) { val[x]+=v; for(;x<=N;x+=x&-x) t[x]+=v; }
int sum(int x) { int ret=0; for(;x;x -= x&-x) ret += t[x]; return ret; }

int search(int pos) {
	int i=1, f=N;
	if(val[1]==pos) return 1;
	while(1) {
		int m = (i+f)/2;
		if(sum(m) < pos) {
			if(sum(m+1) == pos) return m+1;
			i = m+1;
		}
		else {
			if(sum(m-1) < pos) return m;
			f = m-1;
		}
	}
}

int conv(int i) {
	if(i == n+2) return 0;
	if(i < n+2) return i-1;
	if(i > n+2) return n+2-i;
}

void remove(int pos) {
	int p = search(pos+1);
	if(p == n+2) flag = 1;
	if(p==1 || p==n+2) {
		if(tam==2) {
			add(n+2, -1);
			tam--;
		}
		else {
			add(1, -1);
			add(n+2, -1);
			tam -= 2;
		}
	}
	else {
		add(p, -1);
		tam--;
	}
}

int main() {
	ifstream in("infinity.in");
	ofstream out("infinity.out");
	while(in>>n>>m>>k && !in.eof()) {
		flag = 0;
		memset(val,0,sizeof(val));
		memset(t,0,sizeof(t));
		N = tam = n+m+2;
		k--;
		int pos=0;
		for(int i=1;i<=N;i++) add(i, 1);
		while(tam > 1) {
			pos += k;
			pos %= tam;
			remove(pos);
			if(flag) pos--;
			flag = 0;
		}
		for(int i=1;i<=N;i++) if(val[i]==1) {
			out << conv(i) << endl;
			break;
		}
	}   
	return 0;
}

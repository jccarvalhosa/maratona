#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Possibles {
	vector<bool> b;
	Possibles() : b(9, true) {}
	bool valid(int i) { return b[i-1]; }
	int total() { return count(b.begin(), b.end(), true); }
	void remove(int i) { b[i-1] = false; }
	int val() {
		for(int i=0;i<9;i++) if(b[i]) return i+1;
		return -1;
	}
};

vector<vector<int> > group(27), adj(81), groups_of(81);

struct Sudoku {
	vector<Possibles> cell;
	Sudoku(string s) : cell(81) { for(int i=0;i<81;i++) if(s[i] >= '1' && s[i] <= '9') write(i, s[i] - '0'); }

	bool write(int k, int val) {
		for(int i=1;i<=9;i++) if(i != val && !remove(k, i)) return false;
		return true;
	}
	
	bool remove(int k, int val) {
		if(!cell[k].valid(val)) return true;
		cell[k].remove(val);
		int N = cell[k].total();
		if(N == 0) return false;
		if(N == 1) {
			int v = cell[k].val();
			for(int i=0;i<adj[k].size();i++) if(!remove(adj[k][i], v)) return false;
		}
		for(int i=0;i<3;i++) {
			int x = groups_of[k][i];
			int n = 0, ks;
			for(int j=0;j<9;j++) {
				int p = group[x][j];
				if(cell[p].valid(val)) n++, ks=p;
			}
			if(n == 0) return false;
			if(n == 1 && !write(ks, val)) return false;
		}
		return true;
	}
	
	bool is_solved() {
		for(int k=0;k<81;k++) if(cell[k].total() != 1) return false;
		return true;
	}
	
	int best() {
		int k, min=1<<30;
		for(int i=0;i<81;i++) {
			int m = cell[i].total();
			if(m > 1 && m < min) min = m, k = i;
		}
		return k;
	}

	void print() { 
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) cout << cell[i*9 + j].val();
			cout<<endl;
		}
		cout << endl;
	}
};
	
void init() {
	for(int i=0;i<9;i++) for(int j=0;j<9;j++) {
		int k = i*9 + j;
		int x[3] = {i, 9 + j, 18 + (i/3)*3 + j/3};
		for(int g=0;g<3;g++) {
			group[x[g]].push_back(k);
			groups_of[k].push_back(x[g]);
		}
	}
	for(int k=0;k<81;k++) {
		for(int x=0;x<3;x++) for(int j=0;j<9;j++) {
			int k2 = group[groups_of[k][x]][j];
			if(k2 != k) adj[k].push_back(k2);
		}
	}
}

Sudoku* solve(Sudoku *S) {
	if(S == NULL || S->is_solved()) return S;
	int k = S->best();
	Possibles p = S->cell[k];
	for(int i=1;i<=9;i++) {
		if(p.valid(i)) {
			Sudoku *S1 = new Sudoku(*S);
			if(S1->write(k, i)) {
				Sudoku *S2 = solve(S1);
				if (S2 != NULL) {
					if(S2 != S1) delete S1;
					return S2;
				}
			}
			delete S1;
		}
	}
	return NULL;
}

int main() {
	init();
	int T;
	cin>>T;
	while(T--) {
		string s="";
		for(int i=0;i<9;i++) {
			string aux;
			cin>>aux;
			s+=aux;
		}
		Sudoku* S = solve(new Sudoku(s));
		S->print();
		delete S;
	}
}

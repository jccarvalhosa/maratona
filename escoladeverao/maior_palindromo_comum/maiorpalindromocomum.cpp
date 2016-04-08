#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
const lli MOD = 1000000007, BASE = 12345;

int n, maior, menor;
char s[15][50110];
int size[15];

lli base[50110];
lli hash1[50110], hash2[50110];
set<lli> sets[15];

void binaria_par(int a, int b);
void binaria_impar(int a, int b);
bool checa(int t);
void preenche_hash(int t, int j);
void preenche_base();

int main() {
	preenche_base();
	
	/*scanf("%s", s[0]); size[0] = strlen(s[0]); // DEBUG
	preenche_hash(4, 0);
	for(int i=0; i<=(int)strlen(s[0])-4; i++) printf("%lld %lld\n", hash1[i], hash2[i]);*/
	
	while(scanf("%d", &n) != EOF) {
		if(!n) break;
		menor = 100000;
		
		for(int i=0; i<n; i++) {
			scanf("%s", s[i]);
			
			size[i] = strlen(s[i]);
			if(size[i] < menor) menor = size[i];
		}
		
		maior = 0;
		binaria_par(0, menor+1);
		binaria_impar(0, menor+1);
		
		printf("%d\n", maior);
	}
}

void binaria_par(int a, int b) {
	int t;
	
	while(a < b) {
		t = (a+b)/2;
		
		if(checa(t*2)) {
			if(t*2 > maior) maior = t*2;
			a = t+1;
		} else {
			b = t;
		}
	}
}

void binaria_impar(int a, int b) {
	int t;
	
	while(a < b) {
		t = (a+b)/2;
		
		if(checa(t*2+1)) {
			if(t*2+1 > maior) maior = t*2+1;
			a = t+1;
		} else {
			b = t;
		}
	}
}

bool checa(int t) {
	if(t > menor) return false;
	
	preenche_hash(t, 0);
	vector<lli> vetor[10];
	for(int i=0; i<=size[0]-t; i++) if(hash1[i] == hash2[i]) {
		vetor[0].push_back(hash1[i]);
	}
	
	for(int i=1; i<n; i++) {
		preenche_hash(t, i);
		
		for(int j=0; j<=size[i]-t; j++) if(hash1[j] == hash2[j]) {
			vetor[i].push_back(hash1[j]);
		}
		sort(vetor[i].begin(), vetor[i].end());
	}
	
	int size_v = (int)vetor[0].size();
	for(int j=0; j<size_v; j++) {
		int i;
		for(i=1; i<n; i++) if(!binary_search(vetor[i].begin(), vetor[i].end(), vetor[0][j])) {
			break;
		}
		if(i == n) {
			return true;
		}
	}
	
	return false;
}

void preenche_hash(int t, int j) {
	int cont = t-1;
	lli total = 0;
	for(int i=0; i<t; i++) {
		total = (total + (lli)s[j][i]*base[cont--]) % MOD;
	}
	hash1[0] = total;
	for(int i=1; i<=size[j]-t; i++) {
		total = total * BASE;
		total %= MOD;
		total = total+MOD - ((lli)s[j][i-1]*base[t] % MOD);
		total = total + (lli)s[j][i+t-1];
		total %= MOD;
		
		hash1[i] = total;
	}
	
	cont = t-1;
	total = 0;
	for(int i=size[j]-1; i>=size[j]-t; i--) {
		total = (total + (lli)s[j][i]*base[cont--]) % MOD;
	}
	hash2[size[j]-t] = total;
	for(int i=size[j]-t-1; i>=0; i--) {
		total = total * BASE;
		total %= MOD;
		total = total+MOD - ((lli)s[j][i+t]*base[t] % MOD);
		total = total + (lli)s[j][i];
		total %= MOD;
		
		hash2[i] = total;
	}
}

void preenche_base() {
	lli aux = 1;
	
	for(int i=0; i<50100; i++) {
		base[i] = aux;
		
		aux = (aux*BASE) % MOD;
	}
}

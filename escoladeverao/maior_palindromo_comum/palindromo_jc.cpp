#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

/*
    Solução para o problema do maior palíndromo comum
    Problema de: Jonathan Carvalhosa
	Solução de: Jonathan Carvalhosa
	
	A entrada do problema é composta de um inteiro n e um conjunto de strings

	O tamanho maximo de cada string é M = 50000

	O problema consiste em encontrar o tamanho do maior palindromo que é substring de todas as strings da entrada ao mesmo tempo
	Exemplo:

	3
	cabbac
	aaaaaaaaaaaaabba
	bbbbbaabba

	A resposta do problema é 4, porque o maior palíndromo que está contido em todas as strings é abba

	A solução proposta usa hash e busca binária

	A complexidade da solução proposta é o(n*M*log(M)*log(M))

	Dada uma string s de tamanho n, a função de hash escolhida é: h(s) = somatorio de C**(n-i-1) * s[i], onde C é uma constante
	
	Uma string é um palíndromo se a função de hash aplicada nela lida pela esquerda é igual a função de hash aplicada nela lida pela direita
*/

const ll C = 12345;
const ll MOD = (ll)1e9 + 7;
const int M = 50000;
const int N = 10;

ll pot[M], hr[M], hl[M];
string s[N];
int n;

/*
	Verifica se existe algum palindromo de tamanho t que é uma solução para o problema
	
	Para cada string s[i], o hash de todos os palindromos de tamanho t que são substrings de s[i] é armazenado no vetor v[i]

	Se para algum hash guardado em v[0], o mesmo for encontrado em todos os outros vetores, existe uma solução

	Caso contrário não existe nenhuma solução de tamanho t

	O hash é calculado recursivamente a partir da seguinte interpretação:

		hl[j] é o hash calculado pela esquerda para a substring de tamanho t que começa em j (s[i][j] -> s[i][j+t-1])

		hr[j] é o hash calculado pela direita para a substring de tamanho t que começa em j (s[i][j] -> s[i][j-t+1])
		
	Se a substring (s[i][j] -> s[i][j+t-1]) é um palindromo, entao hl[j] tem que ser igual a hr[j+t-1]
*/
int valid(int t) {
	if(t==0) return 1;
	for(int i=0;i<n;i++) if(s[i].size() < t) return 0;
	vector<vector<ll> > v(n);
	for(int i=0;i<n;i++) {
		hl[0]=0;
		for(int j=0;j<t;j++) hl[0] = (hl[0] + pot[t-1-j]*s[i][j])%MOD;
		for(int j=1;j+t-1<s[i].size();j++) hl[j] = ((((hl[j-1] - pot[t-1]*s[i][j-1])*C + s[i][j+t-1]) % MOD) + MOD) % MOD;
		hr[s[i].size()-1]=0;
		for(int j=0;j<t;j++) hr[s[i].size()-1] = (hr[s[i].size()-1] + pot[t-1-j]*s[i][s[i].size() - j - 1]) % MOD;
		for(int j=s[i].size() - 2;j>=t-1;j--) hr[j] = ((((hr[j+1] - pot[t-1]*s[i][j+1])*C + s[i][j-t+1]) % MOD) + MOD) % MOD;
		for(int j=0;j+t-1<s[i].size();j++) if(hl[j] == hr[j+t-1]) v[i].push_back(hl[j]);
		sort(v[i].begin(), v[i].end());
	}
	for(int i=0;i<v[0].size();i++) {
		int j;
		for(j=1;j<n;j++) if(!binary_search(v[j].begin(), v[j].end(), v[0][i])) break;
		if(j==n) return 1;
	}
	return 0;
}

int solve_odd() {
	if(!valid(1)) return 0;
	int l=0, r=M;
	while(l<r-1) {
		int mid = (l+r)/2;
		if(valid(2*mid+1)) l=mid;
		else r=mid;
	}
	return 2*l+1;
}

int solve_even() {
	int l=0, r=M;
	while(l<r-1) {
		int mid = (l+r)/2;
		if(valid(2*mid)) l=mid;
		else r=mid;
	}
	return 2*l;
}

int main() {
	pot[0]=1;
	for(int i=1;i<M;i++) pot[i]=(pot[i-1]*C)%MOD;
	while(cin>>n && !cin.eof()) {
		for(int i=0;i<n;i++) cin>>s[i];

		/*
			Se existe um palindromo p de tamanho n que é uma solução para o problema (n>=2), 
			entao existe um palíndromo de tamanho n-2 que tambem é solução para o problema (o palindromo p retirando-se as duas extremidades)
			
			Se não existe nenhum palindromo de tamanho n que é uma solução para o problema, 
			entao não existe nenhum palíndromo de tamanho n+2 que é solução para o problema (se existisse, poderia-se retirar as extremidades 
			dele e criar uma solução de tamanho n)
			
			Dessa forma, a busca binária tem que ser dividida em duas partes: palíndromos impares e palindromos pares
		*/
		cout << max(solve_odd(), solve_even()) << endl;
	}
	return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

//estou no andar n-1, acabei de tacar um ovo e ele nao quebrou
//sol1[n] retorna o tempo que eu vou demorar para achar a resposta
//estou no andar n com os dois ovos e ja testei todos os andares inferiores
//sol2[n] retorna o tempo que eu vou demorar para achar a resposta
ll N, T, E, sol1[10001], sol2[10001];

//estou parado no andar l e tenho que testar todos os andares de l ate h de 1 em 1
//brute(l, h) retorna o tempo que eu vou gastar para fazer isso:
ll brute(ll l, ll h) { return E*(h-l+1) + T*(h*(h+1)/2 - l*(l+1)/2); }

int main() {
	ll i, j;
	scanf(" %lld %lld %lld", &N, &T, &E);
	sol1[N] = E + T;
	sol2[N] = E;
	for(i=N-1;i>0;i--) {
		//minimo entre tacar o primeiro ovo em j=i ou j=N
		sol2[i] = E + min(sol1[i+1], T*(N-i) + brute(i, N-1));
		for(j=i+1;j<N;j++) {
			sol2[i] = min(sol2[i], E + T*(j-i) + max(brute(i, j-1), sol1[j+1]));
			if(E + T*(j-i) + brute(i, j-1) >= sol2[i]) break;
		}
		//minimo entre tacar o segundo ovo em j=i ou j=N
		sol1[i] = min(T*i + sol2[i], E + min(T + T*(i+1) + sol2[i+1], T*N + brute(i, N-1)));
		for(j=i+1; j < N; j++) {
			sol1[i] = min(sol1[i], E + T * (j-i+1) + max(T*i + brute(i, j-1), T*(j+1) + sol2[j+1]));
			if(E + T*(j+1) + brute(i, j-1) >= sol1[i]) break;
		}
	}
	printf("%lld\n", sol1[1]);
	return 0;
}

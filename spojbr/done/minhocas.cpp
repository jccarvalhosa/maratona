#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main(){
	queue<int> v;
	vector<int> D[3000], Dinv[3000];
	int n,m, conexo, i, j, a, b, A[3000], primeiro, teste=1;
	while(scanf("%d%d", &n, &m) && n){
		for(i=0;i<n;i++) A[i] = 0;
		conexo = 1;
		for(i=0;i<m;i++){
			scanf("%d%d", &a, &b);
			a--; b--;
			D[a].push_back(b);
			Dinv[b].push_back(a);
		}
		//testando a conexidade em uma direcao.
		v.push(0);
		while(!v.empty()){
			primeiro = v.front();
			for(i=0;i<D[primeiro].size();i++) if(!A[D[primeiro][i]]){
				A[D[primeiro][i]] = 1;
				v.push(D[primeiro][i]);
			}
			v.pop();
		}
		for(i=0;i<n;i++) if(A[i] == 0){
			conexo = 0;
			break;
		}
		for(i=0;i<n;i++) A[i] = 0;
		//testando a conexidade na direcao inversa.
		v.push(0);
		while(!v.empty()){
			primeiro = v.front();
			for(i=0;i<Dinv[primeiro].size();i++) if(!A[Dinv[primeiro][i]]){
				A[Dinv[primeiro][i]] = 1;
				v.push(Dinv[primeiro][i]);
			}
			v.pop();
		}
		for(i=0;i<n;i++) if(A[i] == 0){
			conexo = 0;
			break;
		}
		printf("Teste %d\n", teste++);
		if(conexo) printf("S\n\n");
		else printf("N\n\n");
		for(i=0;i<n;i++) D[i].clear(), Dinv[i].clear();
	}
	return 0; 
}



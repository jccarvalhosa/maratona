#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef struct{
	int numero;
	int amigo1;
	int amigo2;
}Crianca;

int main(){
	Crianca aux;
	vector<Crianca> c;
	queue<int> f;
	map<int,int> posicao;
	map<int,int> naoVistos;
	map<int,int>::iterator it;
	int k,w,i,a,b, posa, posb, possivel, contador, amg1, amg2, cor1, cor2, fechado, existe, criancasTotais;
	
	while(1){
		scanf("%d%d", &k, &w);
		if(k == 0 && w == 0) break;
		possivel=1;
		fechado=0;
		//armazena os dados, conferindo se nenhuma crianca esta sendo vizinha de mais de duas outras.
		for(i=0;i<w;i++){
			scanf("%d%d", &a, &b);
			//se ainda nao deu nada errado,
			if(possivel){
				existe = (it != posicao.end());
				it = posicao.find(a);
				//se a crianca 'a' ja apareceu em algum desejo,
				if(existe){
					posa = it->second;
					//se o primeiro amigo nao é a crianca b e o segundo amigo nao foi preenchido, preenche ele com b.
					if(c[posa].amigo1 != b && !c[posa].amigo2) c[posa].amigo2 = b;
					//se ja tiver os dois amigos preenchidos, nao é mais possivel atender aos desejos.
					else if(c[posa].amigo1 != b && c[posa].amigo2 != b){
						possivel = 0;
					}
				}
				//se a crianca 'a' ainda nao apareceu, insere os dados dela.
				else{
					posa = c.size();
					aux.numero = a;
					aux.amigo1 = b;
					aux.amigo2 = 0;
					c.push_back(aux);
					posicao[a] = posa;
					naoVistos[a] = a;
				}
				//mesma coisa para a crianca 'b'.
				it = posicao.find(b);
				existe = (it != posicao.end());
				if(existe){
					posb = it->second;
					if(c[posb].amigo1 != a && !c[posb].amigo2) c[posb].amigo2 = a;
					else if(c[posb].amigo1 != a && c[posb].amigo2 != a){
						possivel = 0;
					}
				}
				else{
					posb = c.size();
					aux.numero = b;
					aux.amigo1 = a;
					aux.amigo2 = 0;
					c.push_back(aux);
					posicao[b] = posb;
					naoVistos[b] = b;
				}
			}		
		}
		//tudo armazenado com sucesso.
		//agora executa o algoritmo para ver se nao tem nenhum caminho fechado.
		//ideia: BFS.
		criancasTotais = c.size();
		for(contador=0;!naoVistos.empty() && possivel;contador++){
			f.push(naoVistos.begin()->second);
			naoVistos.erase(naoVistos.begin());
			while(!f.empty()){
				a = f.front();
				posa = posicao.find(a)->second;
				amg1 = c[posa].amigo1;
				amg2 = c[posa].amigo2;
				if(amg1){
					it = naoVistos.find(amg1);
					cor1 = (it == naoVistos.end());
					//se o amigo 1 ainda nao apareceu, acrescenta ele na fila.
					if(!cor1){
						f.push(amg1);
						naoVistos.erase(it);
					}
				}
				else cor1 = 0;
				if(amg2){
					it = naoVistos.find(amg2);
					cor2 = (it == naoVistos.end());
					//se o amigo 2 ainda nao apareceu, acrescenta ele na fila.
					if(!cor2){
						f.push(amg2);
						naoVistos.erase(it);
					}
				}
				else cor2 = 0;
				//se os dois ja apareceram é pq forma um caminho fechado.
				if(cor1 + cor2 == 2){
					fechado = 1;
				}
				//remove da fila e do vetor de criancas o primeiro elemento.
				f.pop();
			}
		}
		//fim do algoritmo, analiza as informacoes obtidas.
		//se apareceu caminho fechado e contador diferente de 1, é impossivel atender aos desejos das criancas.
		//se apareceu caminho fechado e o numero de criancas vistas foi menor que k, é impossivel também.
		if(fechado && (contador != 1 || criancasTotais != k)) possivel = 0;
		if(possivel) printf("Y\n");
		else printf("N\n");
		c.clear();
		posicao.clear();
		naoVistos.clear();				
	}
	return 0;
}


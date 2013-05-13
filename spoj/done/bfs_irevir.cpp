#include <stdio.h>
#include <queue>

using namespace std;

int D[2000][2000];

int main(){
	queue<int> v;
    int n,m, conexo, i, j, a, b, p, A[2000], primeiro, aux;
    while(1){
       scanf("%d%d", &n, &m);
       if(n == 0 && m == 0) return 0;
       for(i=0;i<n;i++) for(j=0;j<n;j++) D[i][j] = 0;
       for(i=0;i<n;i++) A[i] = 0;
       conexo = 1;
       for(i=0;i<m;i++){
          scanf("%d%d%d", &a, &b, &p);
          D[a-1][b-1] = 1;
          if(p == 2) D[b-1][a-1] = 1;
       }
       //testando a conexidade em uma direcao.
       v.push(0);
       while(!v.empty()){
		   primeiro = v.front();
		   for(i=0;i<n;i++) if(D[primeiro][i] == 1 && !A[i]){
			   A[i] = 1;
			   v.push(i);
		   }
		   v.pop();
	   }
	   for(i=0;i<n;i++) if(A[i] == 0){
		   conexo = 0;
		   break;
	   }
	   for(i=0;i<n;i++) A[i] = 0;
	   //testando a conexidade na direcao inversa.
	   if(conexo == 1){
		   for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
			  aux = D[i][j];
			  D[i][j] = D[j][i];
		      D[j][i] = aux;
	       }
		   v.push(0);
           while(!v.empty()){
		       primeiro = v.front();
		       for(i=0;i<n;i++) if(D[primeiro][i] == 1 && !A[i]){
			       A[i] = 1;
			       v.push(i);
		       }
		       v.pop();
	       }
	       for(i=0;i<n;i++) if(A[i] == 0){
		       conexo = 0;
		       break;
	       }
	   }
	   printf("%d\n", conexo);
   }
   return 0; 
}

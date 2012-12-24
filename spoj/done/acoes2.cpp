#include <cstdio>
#include <queue>
#include <set>
#define sz size()
using namespace std;

int R, M, r[100000], m[100000], pd[2][100001];

int main() {
	int i, j, N, n;
	while(scanf("%d", &N) && N) {
		priority_queue<int> qmin, qmax;
		set<int> s;
		scanf("%d", &m[0]);
		qmin.push(m[0]);
		s.insert(m[0]);
		M=1;
		for(i=1;i<N;i++) {
			scanf("%d", &n);
			if(n < m[M-1]) qmin.push(n);
			else qmax.push(-n);
			if(qmin.sz > qmax.sz + 1) {
				n = qmin.top();
				qmin.pop();
				qmax.push(-n);
			}
			else if(qmax.sz > qmin.sz) {
				n = -qmax.top();
				qmax.pop();
				qmin.push(n);
			}
			m[M] = qmin.top();
			s.insert(m[M]);
			if(m[M] != m[M-1]) M++;
		}
		scanf("%d", &N);
		R=0;
		for(i=0;i<N;i++) {
			scanf("%d", &r[R]);
			if(s.count(r[R])) R++;
		}
		for(i=0;i<=R;i++) pd[0][i] = 0;
		for(i=1;i<=M;i++) for(j=1;j<=R;j++) {
			pd[i%2][j] = max(pd[(i+1)%2][j], pd[i%2][j-1]);
			if(m[i-1] == r[j-1]) pd[i%2][j] = max(pd[i%2][j], pd[(i+1)%2][j-1]+1);
		}
		printf("%d\n", pd[M%2][R]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#define MAX 1500000
#define NMAX 100000

int ss, size, num[MAX], end[MAX], nadj[MAX], adj[MAX][26];
char s[NMAX];
double sum;

void reset(int v) {
	num[v] = end[v] = nadj[v] = 0;
	for(int i=0;i<26;i++) adj[v][i] = -1;
}

void insert(int v, int pos) {
	num[v]++;
	if(pos != ss) {
		if(adj[v][s[pos]-'a'] == -1) {
			reset(size);
			adj[v][s[pos]-'a'] = size++;
			nadj[v]++;
		}
		insert(adj[v][s[pos]-'a'], pos+1);
	}
	else {
		end[v]++;
		nadj[v]++;
	}
}

void dfs(int v) {
	if(!v || nadj[v]>1) sum += num[v] - end[v];
	for(int i=0;i<26;i++) if(adj[v][i]!=-1) dfs(adj[v][i]);
}

int main() {
	int N, i;
	while(scanf("%d", &N) != EOF) {
		sum=0;
		size=1;
		reset(0);
		for(i=0;i<N;i++) {
			scanf("%s", s);
			ss = strlen(s);
			insert(0, 0);
		}
		dfs(0);
		printf("%.2lf\n", sum/N);
	}
	return 0;
}

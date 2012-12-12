#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <sstream>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz size()
#define INF 1000000000
using namespace std;
int mod(int a) { return a > 0 ? a : -a; }
typedef vector<int> vi;
typedef vector<string> vs;

map<vi, int> id;
vs expr;
vi pai;
char oper[4] = {'+', '-', '*', '/'};
int n, aprox, bid;

int exec(int a, int b, int op) {
    switch(op) {
        case 0: return a+b;
        case 1: return a-b;
        case 2: return a*b;
        case 3: return b != 0 && a%b == 0 ? a/b : INF;
    }
}

//Cada mão v tem:
// -  um pai p, que é a mão que gerou v
// -  uma string s, que é a string referente a jogada que foi feita para p gerar v
//Exemplo:
// pai = [1, 2, 3, 5, 5]
// s = "5 + 5 = 10"
// v = [1, 2, 3, 10]
//Esse dfs gera todas as possibilidades e só corta quando a aproximação é exatamente igual ao número n procurado
void dfs(vi v, vi p, string s) {
    int i, j, k, op, elem;
    if(aprox == n) return;
    id[v] = id.sz - 1;
    pai.pb(id[p]);
    expr.pb(s);
    for(i=0;i<v.sz;i++) if(mod(v[i]-n) < mod(aprox-n)) aprox = v[i], bid = id[v];
    for(i=0;i<v.sz;i++) for(j=i+1;j<v.sz;j++) for(op=0;op<4;op++) {
        vector<int> u;
        stringstream ss;
        for(k=0;k<v.sz;k++) if(k != i && k != j) u.pb(v[k]);
        elem = exec(v[j], v[i], op);
        u.pb(elem);
        sort(all(u));
        if(!id.count(u) && elem != INF) {
            ss << v[j] << " " << oper[op] << " " << v[i] << " = " << elem;
            dfs(u, v, ss.str());
        }
    }
}

int main()
{
    int T, i, m[6];
    scanf("%d", &T);
    while(T--) {
        id.clear();
        expr.clear();
        pai.clear();
        for(i=0;i<6;i++) scanf("%d", &m[i]);
        scanf("%d", &n);
        vi v(m, m+6);
        aprox = INF;
        bid = -1;
        sort(all(v));
        dfs(v, v, "");
        printf("Target: %d\n", n);
        vs vexp;
        for(i=bid; pai[i] != i; i = pai[i]) vexp.pb(expr[i]);
        for(i=vexp.sz-1;i>=0;i--) cout << vexp[i] << endl;
        printf("Best approx: %d\n\n", aprox);
    }
    return 0;
}

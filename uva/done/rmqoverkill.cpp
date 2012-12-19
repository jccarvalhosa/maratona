#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;

int main() {
    int N, i, x, pos, a, b;
    char c[10001];
    while(scanf("%d", &N) != EOF) {
        scanf("%s", c);
        vector<pii> v(N);
        for(i=0;i<N;i++) v[i] = make_pair(c[i]-'0', i);
        sort(v.begin(), v.end());
        set<int> s;
        set<int>::iterator ita, itb;
        s.insert(-1);
        s.insert(N);
        int resp=0;
        for(i=0;i<N;i++) {
            pos = v[i].second;
            s.insert(pos);
            x = v[i].first;
            ita = itb = s.find(pos);
            ita--; itb++;
            resp = (resp + x*(*itb - pos)*(pos - *ita)) % MOD;
        }
        printf("%d\n", resp);
    }
    return 0;
}

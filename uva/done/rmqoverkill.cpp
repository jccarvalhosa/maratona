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
        s.insert(-1);
        s.insert(N);
        int resp=0;
        for(i=0;i<N;i++) {
            pos = v[i].second;
            a = *(--s.lower_bound(pos));
            b = *(s.upper_bound(pos));
            s.insert(pos);
            x = v[i].first;
            resp = (resp + x*(b-pos)*(pos-a)) % MOD;
        }
        printf("%d\n", resp);
    }
    return 0;
}

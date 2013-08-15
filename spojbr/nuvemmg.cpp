#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 1000000000

using namespace std;

int main()
{
    int pd[500][500], v[1000];
    vector<pair<int, int> > vd;
    int N, L, i, j, k, d, val, resp, custo;
    while(scanf("%d%d", &N, &L) && N)
    {
        vd.clear();
        for(i=0;i<N;i++) scanf("%d%d", &d, &val), vd.push_back(make_pair(d-1, val));
        sort(vd.begin(), vd.end());
        for(i=0;i<vd.size();i++) v[i] = vd[i].second;
        for(i=0;i<N;i++) for(j=0;j<L;j++) pd[i][j] = INF;
        pd[N-1][L-1] = v[N-1];
        for(i=N-2;i>=0;i--) for(j=0;j<L-1;j++) for(k=i+1;k<N;k++) pd[i][j] = min(pd[i][j], pd[k][j+1] + (k-i-1)*v[k] + v[i]);
        resp = INF;
        for(i=0;i<N;i++) for(j=0;j<L;j++)
        {
            custo = pd[i][j];
            if(i > 0) custo += i*v[i];
            resp = min(resp, custo);
        }
        printf("%d\n", resp);
    }
    return 0;
}

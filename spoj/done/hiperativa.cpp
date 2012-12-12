#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

int main()
{
    int M, N, i, j, k, sum;
    int s[100][100];
    vector<pair<int, int> > v;
    while(scanf("%d%d", &M, &N) && M)
    {
        v.clear();
        memset(s, 0, sizeof(s));
        for(i=0;i<N;i++)
        {
            scanf("%d%d", &j, &k);
            v.push_back(make_pair(j, k));
        }
        sort(v.begin(), v.end());
        sum = 0;
        for(i=0;i<N;i++)
        {
            if(v[i].first == 0 && v[i].second == M) s[i][i] = 1;
            for(j=0;j<i;j++) if(v[j].first == 0 && v[i].first <= v[j].second && v[i].second > v[j].second && v[i].first > 0) s[i][j]=1;
        }
        for(i=0;i<N;i++) for(j=0;j<i;j++) if((v[i].first <= v[j].second) && (v[i].second > v[j].second) && (v[i].first > v[j].first))
                for(k=0;k<j;k++) if(v[i].first > v[k].second) s[i][j] += s[j][k];
        for(i=0;i<N;i++) for(j=0;j<=i;j++) if(v[i].second == M) sum = (sum + s[i][j]) % 100000000;
        printf("%d\n", sum);
    }
    return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, resp, i;
    double R, ming, lixo, x;  
    vector<double> v;
    while(scanf("%d%lf", &N, &R) && N)
    {
        v.clear();
        for(i=0;i<N;i++) {
            scanf("%lf%lf", &x, &lixo);
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        resp = 1;
        ming = v[0];
        for(i=1;i<N;i++) if(v[i] / ming > R) {
            resp++;
            ming = v[i];
        }
        printf("%d\n", resp);
    }
    return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i, j, n, p, c, aux=1;
    char op[2];
    vector<int> v;
    while(scanf("%d %d", &p, &c) && (p || c))
    {
        n=min(p, c);
        v.clear();
        for(i=1; i<=n; i++) v.push_back(i);
        printf("Case %d:\n", aux++);
        for(i=0; i<c; i++)
        {
            scanf("%s", op);
            if(op[0]=='N')
            {
                printf("%d\n", v[0]);
                n=v[0];
                v.erase(v.begin());
                v.push_back(n);
            }
            else
            {
                scanf("%d", &n);
                for(j=0; j<v.size(); j++) if(v[j]==n) break;
                if(j==(int)v.size()) v.insert(v.begin(), n);
                else
                {
                    v.erase(v.begin()+j);
                    v.insert(v.begin(), n);
                }
            }
        }
    }
    return 0;
}

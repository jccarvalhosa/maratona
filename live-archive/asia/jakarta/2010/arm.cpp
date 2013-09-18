#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int p[44444], k, n, M[333333], M0[333333], i0[333333];
vector<int> v;

void init(int node, int b, int e)
{
    if(b==e)
    {
        M[node]=M0[node]=p[b];
        i0[node]=b;
    }
    else
    {
        int m=(b+e)/2;
        init(2*node, b, m);
        init(2*node+1, m+1, e);
        if(M[2*node]>=M[2*node+1])
        {
            M0[node]=M0[2*node];
            M[node]=min(M0[2*node], M[2*node]-M[2*node+1]+k);
            i0[node]=i0[2*node];
        }
        else
        {
            M0[node]=M0[2*node+1];
            M[node]=min(M0[2*node+1], M[2*node+1]-M[2*node]+k);
            i0[node]=i0[2*node+1];
        }
    }
}

void print(int node)
{
    if(node>=(1<<n)) return;
    if(M[2*node]>=M[2*node+1])
    {
        print(2*node);
        v.push_back(i0[2*node+1]+1);
    }
    else
    {
        print(2*node+1);
        v.push_back(i0[2*node]+1);
    }
}

int main()
{
    int i, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        v.clear();
        for(i=0; i<(1<<n); i++) scanf("%d", &p[i]);
        init(1, 0, (1<<n)-1);
        print(1);
        printf("%d\n", i0[1]+1);
        printf("%d", v[0]);
        for(i=1; i<v.size(); i++) printf(" %d", v[i]);
        printf("\n");
    }
    return 0;
}

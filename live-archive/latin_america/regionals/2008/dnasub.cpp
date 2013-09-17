#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define sz size()

using namespace std;

int pd[1001][1001];

int main()
{
    int K, i, j, m;
    string a, b;
    while(scanf("%d", &K) && K) {
        cin >> a >> b; 
        for(i=0;i<=a.sz;i++) for(j=0;j<=b.sz;j++) pd[i][j] = 0;
        for(i=K;i<=a.sz;i++) for(j=K;j<=b.sz;j++) {
            pd[i][j] = max(pd[i][j-1], pd[i-1][j]);
            for(m=1; m<=i && m<=j && a[i-m] == b[j-m]; m++)
                if(m >= K) 
                    pd[i][j] = max(pd[i][j], m + pd[i-m][j-m]);
        }
        printf("%d\n", pd[a.sz][b.sz]);
    }
    return 0;
}

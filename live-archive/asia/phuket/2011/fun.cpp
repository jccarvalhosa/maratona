#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

vector<int> el[1111];

int main() {
    int T, n, m;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        for(int i=0;i<m;i++) {
            char s[111];
            el[i].clear();
            scanf(" %[^\n]", s);
            int tam = strlen(s);
            for(int j=0;j<tam;j++) {
                if(isdigit(s[j]) && (j==(tam-1) || !isdigit(s[j+1]))) {
                    el[i].push_back(s[j]-'0'-1);
                }
                else if(isdigit(s[j]) && isdigit(s[j+1])) {
                    el[i].push_back(10 * (s[j]-'0') + s[j+1]-'0'-1);
                    j++;
                }
            }
        }
        int i, j, k;
        for(i=0;i<(1<<n);i++) {
            for(j=0;j<m;j++) if(el[j].size() >= 2) {
                int c[2]={0,0};
                for(k=0;k<el[j].size();k++) {
                    if(i & (1<<el[j][k])) c[1]++;
                    else c[0]++;
                }
                if(!c[0] || !c[1]) break;
            }
            if(j==m) break;
        }
        if(i==(1<<n)) cout<<"N";
        else cout<<"Y";
    }
    return 0;
}

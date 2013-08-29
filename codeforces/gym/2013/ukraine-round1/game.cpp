#include <iostream>
#include <cstdio>
using namespace std;

int g[5] = {0,0,1,1,2};

int main() {
    int n, p;
    cin >> n;
    int ret=0;
    for(int i=0;i<n;i++) {
        cin >> p;
        ret ^= g[p%5];
    }
    if(ret == 0) cout << "Watson" << endl;
    else cout << "Rybka" << endl;
    return 0;
}

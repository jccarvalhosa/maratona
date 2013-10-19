#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s[111];

int main() {
    int h, w;
    while(scanf("%d%d", &h, &w) != EOF) {
        int q=0, t=0;
        for(int i=0;i<h;i++) cin >> s[i];
        for(int i=0;i<h;i++) {
            int in=0;
            for(int j=0;j<w;j++) {
                if(s[i][j] != '.') {
                    in = 1-in;
                    t++;
                }
                if(s[i][j] == '.' && in) q++;
            }
        }
        cout << t/2 + q << endl;
    }
    return 0;
}

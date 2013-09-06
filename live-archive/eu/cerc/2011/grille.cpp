#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int a[4][1111][1111];
string m[1111];

int main() {
    int n, p;
    char c;
    while((cin>>n) && n) {
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
            cin >> c;
            a[0][i][j] = a[1][j][n-i-1] = a[2][n-i-1][n-j-1] = a[3][n-j-1][i] = (c == 'O' ? 1 : 0);
        }
        for(int i=0;i<n;i++) cin >> m[i];
        for(int i=0;i<4;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) if(a[i][j][k] == 1) cout << m[j][k]; 
        cout << endl;
    }
    return 0;
}

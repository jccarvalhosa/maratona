#include <iostream>
using namespace std;

int a[3][3];

int main() {
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin >> a[i][j];
    int n=0, p=0;
    for(int i=0;i<3;i++) {
        int aux=1;
        for(int j=0;j<3;j++) aux *= a[j][(j+i)%3];
        p += aux;
    }
    for(int i=0;i<3;i++) {
        int aux=1;
        for(int j=0;j<3;j++) aux *= a[j][(3+i-j)%3];
        n += aux;
    }
    cout << (p - n) << endl;
    return 0;
}

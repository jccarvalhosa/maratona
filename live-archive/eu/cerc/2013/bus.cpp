#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
		long long k = 1;
		int a;
		cin >> a;
       	for(int j=1;j<a;j++) { k*=2; k++; } 
       	cout << k << endl;
    } 
    return 0;
}

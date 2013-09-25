#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<char, int> pci;

int pos[111111];
char m[1111][1111], ms[1111][1111];

int main() {
    string c, s;
    while(1) {
        cin>>c;
        if(c == "THEEND") break;
        cin>>s;
        vector<pci> v;
        int k = c.size();
        int N = s.size();
        int n = N/k;
        int p=0;
        for(int j=0;j<k;j++) for(int i=0;i<n;i++) m[i][j] = s[p++];
        for(int i=0;i<k;i++) v.push_back(pci(c[i], i));
        sort(v.begin(), v.end());
        for(int i=0;i<k;i++) pos[i] = v[i].second;
        for(int j=0;j<k;j++) for(int i=0;i<n;i++) ms[i][pos[j]] = m[i][j];
        for(int i=0;i<n;i++) for(int j=0;j<k;j++) printf("%c", ms[i][j]);
        printf("\n");
    }
    return 0;
}

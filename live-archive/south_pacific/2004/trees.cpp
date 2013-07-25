#include <string>
#include <iostream>
#include <vector>
using namespace std;

string s;
vector<int> v;

void dfs(int l, int h, int ini, int fim) {
    if(ini>fim || l>h) return;
    if(l==h) {
        v.push_back(l);
        return;
    }
    int d=0, my, x=0;
    int virgula;
    for(int i=ini;i<=fim;i++) {
        if(s[i]=='(') d++;
        if(s[i]==')') {
            d--;
            x++;
        }
        if(s[i]==',' && d==1) {
            my=l+x;
            virgula=i;
        }
    }
    v.push_back(my);
    dfs(l, my-1, ini+1, virgula-1);
    dfs(my+1, h, virgula+1, fim-1);
}

int main() {
    while(1) {
        cin>>s;
        v.clear();
        if(s=="()") break;
        int m=0;
        for(int i=0;i<s.size();i++) if(s[i]=='(') m++;
        dfs(1, m, 0, s.size()-1);
        cout<<v[0];
        for(int i=1;i<v.size();i++) cout<<" "<<v[i];
        cout<<endl;
    }
    return 0;
}

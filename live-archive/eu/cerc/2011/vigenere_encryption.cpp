#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, cifer;
    while(1) {
        cin>>cifer;
        if(cifer[0]=='0') return 0;
        cin>>s;
        while(cifer.size() < s.size()) cifer += cifer;
        cifer = cifer.substr(0, s.size());
        for(int i=0;i<s.size();i++) cout<<(char)('A' + (s[i]-'A'+cifer[i]-'A'+1)%26);
        cout<<endl;
    }
}

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int v[100000];

int main() {
	for(int i=0;i<4;i++) v[i]=i;
    int i0, i1;
    string s;
    while(scanf("%d", &i0) != EOF) {
        cin>>s>>i1;
        int at=v[i1];
        for(int i=s.size()-1;i>=0;i--) {
            char c = s[i];
            if(c=='f') {
                if(at%2==0) at+=3;
                else at+=1;
            }
            else if(c=='b') at -= 2;
            else if(c=='k') printf("%d\n", at);
            else if(c=='<') v[i0]=at;
            else if(c=='=') printf("%c\n", v[i0]==at ? '=' : '#');
        }
    }
    return 0;
}

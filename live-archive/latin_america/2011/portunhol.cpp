#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

vector<string> query, q;

string reverse(string s) {
    string aux = "";
    for(int i=s.size()-1;i>=0;i--) aux += s[i];
    return aux;
}

int num[26];
long long match, t1, t2, t3;

struct trie {
    map<char, trie> child;

    void insert(string s, int pos, int flag) {
        if(pos != s.size()) {
            if(pos > 0 && !child.count(s[pos])) {
                if(flag == 0) num[s[pos]-'a']++;
                else t3 += num[s[pos]-'a'];
            }
            child[s[pos]].insert(s, pos+1, flag);
        }
    }

    void find(string s, int pos) {
        map<char, trie>::iterator it;
        if(pos < s.size()) { if(child.count(s[pos])) child[s[pos]].find(s, pos+1); }
        else {
            match++;
            for(it=child.begin(); it!=child.end(); it++) (*it).second.find(s, pos);
        }
    }
};

trie port, spa;

int main() {
    int P, S, i, j;
    string s;
    while(scanf("%d%d", &P, &S) && P) {
        port.child.clear();
        spa.child.clear();
        memset(num, 0, sizeof(num));
        for(i=0;i<P;i++) {
            cin >> s;
            port.insert(s, 0, 0);
        }
        match=0;
        port.find("", 0);
        t1 = match-1;
        query.clear();
        t3 = 0;
        for(i=0;i<S;i++) {
            cin >> s;
            spa.insert(reverse(s), 0, 1);
        }
        match=0;
        spa.find("", 0);
        t2 = match-1;
        printf("%lld\n", t1*t2-t3);
    }
    return 0;
}

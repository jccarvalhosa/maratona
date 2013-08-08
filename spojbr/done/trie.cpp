#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> query;

struct trie
{
    vector<string> values;
    map<char, trie> children;

    void insert(string s, int pos)
    {
        if(pos == s.size()) values.push_back(s);
        else children[s[pos]].insert(s, pos+1);
    }
    
    void find(string s, int pos)
    {
        map<char, trie>::iterator it;
        if(pos < s.size()) { if(children.count(s[pos]) > 0) children[s[pos]].find(s, pos+1); }
        else for(it=children.begin(); it!=children.end(); it++) (*it).second.find(s, pos);
        for(int i=0;i<values.size();i++) query.push_back(values[i]);
    }

    void match(string s) { query.clear(); find(s, 0); }
};

int main()
{
    char s[100];
    trie t;
    while(scanf("%s", s) != EOF) t.insert(s, 0);
	t.match("amoro");
    for(int i=0;i<query.size();i++) cout << query[i] << endl;
    return 0;
}

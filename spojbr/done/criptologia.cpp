#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int T, F, i, teste=1;
    string s, c;
    vector<pair<int, int> > num;
    char conv[26];
    while(scanf("%d%d", &T, &F) && T)
    {
        cin >> c;
        num.clear();
        for(i=0;i<26;i++) num.push_back(make_pair(0, i));
        getchar();
        getline(cin, s);
        for(i=0;i<s.size();i++) if(s[i] != ' ') num[s[i]-'a'].first--;
        sort(num.begin(), num.end());
        for(i=0;i<c.size();i++) conv[num[i].second] = c[i];
        printf("Teste %d\n", teste++);
        for(i=0;i<s.size();i++) printf("%c", s[i] == ' ' ? ' ' : conv[s[i]-'a']);
        printf("\n\n");
    }
    return 0;
}

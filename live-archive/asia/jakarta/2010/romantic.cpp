#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int o[52];
vector <int> v[2];

int val(string c)
{
    int ret = 0;
    if(c[0] == '2') ret += 0;
    else if(c[0] == '3') ret += 4;
    else if(c[0] == '4') ret += 8;
    else if(c[0] == '5') ret += 12;
    else if(c[0] == '6') ret += 16;
    else if(c[0] == '7') ret += 20;
    else if(c[0] == '8') ret += 24;
    else if(c[0] == '9') ret += 28;
    else if(c[0] == 'T') ret += 32;
    else if(c[0] == 'J') ret += 36;
    else if(c[0] == 'Q') ret += 40;
    else if(c[0] == 'K') ret += 44;
    else if(c[0] == 'A') ret += 48;
    if(c[1] == 'D') ret += 0;
    else if(c[1] == 'C') ret += 1;
    else if(c[1] == 'H') ret += 2;
    else if(c[1] == 'S') ret += 3;
    return ret;
}

int main()
{
    int n;
    string s;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        memset(o,0,sizeof(o));
        v[0].clear();
        v[1].clear();
        for(int j=0;j<26;j++)
        {
            cin >> s;
            o[val(s)] = 1;
        }
        for(int j=0;j<52;j++)
        {
            if(o[j] == 0) v[1].push_back(j);
            else v[0].push_back(j);
        }
        int pos = 25;
        int ret = 0;
        for(int j=25;j>=0;j--)
        {
            if(v[0][pos] > v[1][j])
            {
                ret++;
                pos--;
            }
        }
        cout << ret << endl;
    }
    return 0;
}

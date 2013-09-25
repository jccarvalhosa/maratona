#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string rev(string s, int m)
{
    int i=0;
    while(i<s.length())
    {
        reverse(s.begin()+i, s.begin()+min((int)s.length(), i+m));
        i+=m;
    }
    return s;
}

int main()
{
    int t, s, m, n, sz;
    string aux, ci, cr;
    cin >> t;
    while(t--)
    {
        ci="";
        cin >> n;
        while(1)
        {
            cin >> aux;
            ci+=aux;
            if(ci.length()==n) break;
        }
        cin >> cr;
        sz=cr.length();
        int j, f=0;
        for(s=1; s<=25; s++)
        {
            for(m=5; m<=20; m++)
            {
                aux=rev(ci, m);
                for(int i=0; i<=n-sz; i++) 
                {
                    for(j=0; j<sz; j++) if((aux[i+j]-'A'+26-s)%26+'A'!=cr[j]) break;
                    if(j==sz) break;
                }
                if(j==sz) break;
            }
            if(j==sz) break;
        }
        if(j==sz) cout << s << " " << m << endl;
        else cout << "Crib is not encrypted." << endl;
    }
    return 0;
}

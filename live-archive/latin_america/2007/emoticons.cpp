#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, i, j, resp, cont[100];
    string s;
    vector<string> emot;
    while(scanf("%d%d", &N, &M) && N)
    {
        emot.clear();
        resp = 0;
        for(i=0;i<N;i++)
        {
            cin >> s;
            emot.push_back(s);
        }
        getchar();
        while(M--)
        {
            getline(cin, s);
            for(i=0;i<N;i++) cont[i] = 0;
            for(i=0;i<s.size();i++)
            {
                for(j=0;j<N;j++)
                {
                    if(emot[j][cont[j]] == s[i])
                    {
                        cont[j]++;
                        if(cont[j] == emot[j].size())
                        {
                            resp++;
                            for(j=0;j<N;j++) cont[j] = 0;
                            break;
                        }
                    }
                    else
                    {
                        if(emot[j][0] == s[i]) cont[j] = 1;
                        else cont[j] = 0;
                    }
                }
            }
        }
        cout << resp << endl;
    }
    return 0;
}

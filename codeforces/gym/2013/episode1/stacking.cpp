#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t[33][33][33];

int main()
{
    int rm, cm, n, x;
    while(scanf("%d" , &n) && n)
    {
        rm = cm = 0;
        memset(t,0,sizeof(t));
        for(int i=0;i<n;i++)
        {
            int j=0;
            while(scanf("%d", &x) && x)
            {
                rm = max(rm,x);
                for(int k=0;k<x;k++) t[i][j][k] = 1;
                j++;
            }
            cm = max(cm,j);
        }
        for(int i=0;i<rm;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c=0;
                for(int k=0;k<cm;k++) c += t[j][k][i];
                if(c > 0)
                {
                    if(j == 0) printf("%d", c);
                    else printf(" %d", c);
                }
            }
            cout << endl;
        }
        cout << endl;
        for(int i=0;i<cm;i++)
        {
            for(int j=0;j<rm;j++)
            {
                int c=0;
                for(int k=0;k<n;k++) c += t[k][i][j];
                if(c > 0)
                {
                    if(j == 0) printf("%d", c);
                    else printf(" %d", c);
                }
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    return 0;
}

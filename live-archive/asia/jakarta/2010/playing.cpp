#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        ll g=0, a;
        int n;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> a;
            if(a%2 == 0) g ^= (a/2);
            else
            {
                while(a%2 == 1)
                {
                    a /= 2;
                }
                g ^= (a/2);
            }
        }
        if(g == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}

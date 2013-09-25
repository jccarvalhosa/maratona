#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF)
    {
        int c = n;
        int b = n;
        while(b/k > 0)
        {
            c += b/k;
            b = b/k + b%k;
        }
        cout << c << endl;
    }
    return 0;
}

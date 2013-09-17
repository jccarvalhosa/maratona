#include <stdio.h>
#include <algorithm>
#define INF 1000000000;

using namespace std;

int rol[250], vb[200], S;

int valor(int b, int pos) { return -(vb[b] * (rol[pos%S] + rol[(pos+1)%S])); }

int main()
{
    int i, j, B, start, lucro;
    int M[250][250], Mmax[250][250];
    while(scanf("%d%d", &S, &B) && S)
    {
        for(i=0;i<S;i++) scanf("%d", &rol[i]);
        for(i=0;i<B;i++) scanf("%d", &vb[i]);
        lucro = -INF;
        for(start=0;start<S;start++)
        {
            M[0][0] = Mmax[0][0] = valor(0, start);
            for(j=1;j<S-1;j++)
            {
                M[0][j] = -INF;
                Mmax[0][j] = max(M[0][j], Mmax[0][j-1]);
            }
            for(i=1;i<B;i++)
            {
                Mmax[i][2*i-2] = Mmax[i][2*i-1] = -INF;
                for(j=2*i;j<S - 2*(B-i-1) - 1;j++) 
                {
                    M[i][j] = Mmax[i-1][j-2] + valor(i, start+j);
                    Mmax[i][j] = max(Mmax[i][j-1], M[i][j]);
                }
            }
            for(j=2*(B-1);j<S-1;j++) lucro = max(lucro, M[B-1][j]);
        }
        printf("%d\n", lucro);
    }
    return 0;
}

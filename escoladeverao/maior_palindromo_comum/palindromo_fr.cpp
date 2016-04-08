#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>

using namespace std;

const int M = 55555;
const int N = 11;
const int K = N*M+1;
int MSK = 0;
int n;
char dic[N][M];
/* 
    Solução para o problema do maior palíndromo comum
    Problema de: Jonathan Carvalhosa
    Solução de: Felipe Rasinhas
    Solução: Busca binária no tamanho da solução com um verificador em o(K).
             São pré calculados o Longest commom preffix [LCP] em o(K*log(K)) e o Longest
             palindromic substring [LPS] em o(K). Com isso é possivel verificar se, para cada
             sufixo das palavras, existe um palíndromo de tamanho k que seja prefixo dele.
             Percorrendo o LCP podemos verificar se esta substring palindromica de tamanho k
             também pertence às outras palavras do conjunto utilizando uma máscara de inteiros.
    Complexidade final: o(K*log(K))
*/

/* Suffix Array o(K*log(K)) */
int wx[K], wy[K], *x, *y, wss[K], wv[K];
int l, len[K];
char s[K];
int sa[K], rnk[K], lcp[K], id[K], dis[K];

bool cmp(int *r,int n,int a,int b,int l) { return a+l<n && b+l<n && r[a]==r[b]&&r[a+l]==r[b+l]; }

void da(char str[],int sa[],int rnk[],int lcp[],int n,int m)
{
    char *s = str;
    int *x=wx, *y=wy, *t,p;
    int i, j, k;
    int v = l;
    for(i=0;i<m;i++) wss[i]=0;
    for(i=0;i<n;i++) wss[x[i]=s[i]]++;
    for(i=1;i<m;i++) wss[i]+=wss[i-1];
    for(i=n-1;i>=0;i--) sa[--wss[x[i]]]=i;
    for(j=1,p=1;p<n && j<n;j*=2,m=p)
    {
        for(i=n-j,p=0;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]-j>=0)y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wss[i]=0;
        for(i=0;i<n;i++) wss[wv[i]]++;
        for(i=1;i<m;i++) wss[i]+=wss[i-1];
        for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0;i<n;i++)
            x[sa[i]] = cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(i=0;i<n;i++) rnk[sa[i]]=i;
    for(i=0,j=0,k=0;i<n;lcp[rnk[i++]]=k) if(rnk[i]>0) for(k?k--:0,j=sa[rnk[i]-1];i+k < n && j+k < n && str[i+k]==str[j+k];k++);
}
/* Suffix Array end */

/* Manacher o(K) */
int lps[2*(K+2)];
char man[2*(K+2)];

void build()
{
    int i=0;
    man[0] = '^';
    man[1] = '|';
    while(s[i] != '\0')
    {
        man[2*(i+1)+1] = '|';
        man[2*(i+1)] = s[i];
        i++;
    }
    man[2*i+2] = '$';
}

void manacher()
{
    int k=0, r=0;
    int l = strlen(man);
    for(int i=1;i<l;i++)
    {
        int o = 2*k-i;
        lps[i] = (r>i) ? min(r-i,lps[o]) : 0;
        while(man[i+1+lps[i]] == man[i-1-lps[i]]) lps[i]++;
        if(i+lps[i] > r) 
        {
            k = i;
            r = i + lps[i];
        }
    }
}
/* Manacher end */

/* Verificador de palindromo o(1) */
int is_palindrome(int pos, int sz)
{
    int manpos = 2 + 2*(pos);
    if(lps[manpos + sz - 1] >= sz) return 1;
    return 0;
}
/* Verificador de palindromo end */

/* Validador o(K) */
int valid(int k)
{
    int ok = 0;
    int msk = 0;
    for(int i=n;i<l;i++)
    {
        if(dis[sa[i]] < k)
        {
            ok = 0;
            msk = 0;
            continue;
        }
        if(!ok)
        {
            ok = is_palindrome(sa[i], k);
            if(ok) msk = (1 << id[sa[i]]);
        }
        else
        {
            if(lcp[i] >= k) msk |= (1 << id[sa[i]]);
            else 
            {
                ok = 0;
                msk = 0;
            }
        }
        if(msk == MSK) return 1;
    }
    return 0;
}
/* Validador end */

/* Solver (o(K*log(K)) */
int bin_odd()
{
    if(!valid(1)) return 0;
    int lo=0, hi=M;
    while(lo < hi-1)
    {
        int mi = (lo+hi)/2;
        if(valid(2*mi+1)) lo = mi;
        else hi = mi;
    }
    return 2*lo+1;
}

int bin_even()
{
    int lo=0, hi=M;
    while(lo < hi-1)
    {
        int mi = (lo+hi)/2;
        if(valid(2*mi))lo = mi;
        else hi = mi;
    }
    return 2*lo;
}
/* Solver end */

int main()
{
    cin >> n;

    /* Parte 1
        Montando o suffix array para verificar a validade da solução
    */
    for(int i=0;i<n;i++)
    {
        scanf("%s",dic[i]);
        len[i] = strlen(dic[i]);
        for(int j=0;j<len[i];j++)
        {
            id[l] = i;
            dis[l] = len[i]-j;
            s[l++] = dic[i][j];
        }
        id[l] = n;
        s[l++] = '!'+i;
    }
    s[l] = 0;
    lcp[l] = 0;
    da(s,sa,rnk,lcp,l,128);
    // Debug -- Print do Suffix array
    // for(int i=n;i<l;i++) printf("id = %d -- lcp = %d -- dis = %d ------ %s\n", sa[i], lcp[i], dis[sa[i]], s+sa[i]);

    /* Parte 2 
        Montando o lps para fazer a verificação se uma string é palíndromo
    */
    build();
    manacher();
    // Debug -- Print do Manacher
    /*
    int l = strlen(man);
    for(int i=0;i<l;i++) printf("%3d",i);
    cout << endl;
    for(int i=0;i<l;i++) printf("%3c",man[i]);
    cout << endl;
    for(int i=0;i<l;i++) printf("%3d",lps[i]);
    cout << endl;
    */

    /* Parte 3
        Fazendo a busca binária pros palíndromos pares e ímpares
    */
    MSK = (1<<n)-1;
    cout << max(bin_even(),bin_odd()) << endl;
    return 0;
}

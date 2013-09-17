#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

char el[30], er[30];
int basemin;

int max(int a, int b) { return a > b ? a : b; }
int mod(int a) { return a > 0 ? a : -a; }
int IS_NUM(char c) { return c >= '0' && c <= '9'; }

typedef struct
{
    int c[20];
    int grau;
} polinomio;

typedef struct
{
    polinomio pol[200];
    int n;
} pilha;

void imprimir(polinomio p)
{
    int i;
    for(i=0;i<p.grau;i++) printf("%d ", p.c[i]);
    printf("\n");
}

polinomio soma(polinomio a, polinomio b)
{
    polinomio resp;
    int i, v1, v2;
    resp.grau = max(a.grau, b.grau);
    for(i=0;i<resp.grau;i++)
    {
        v1 = v2 = 0;
        if(i < a.grau) v1 = a.c[i];
        if(i < b.grau) v2 = b.c[i];
        resp.c[i] = v1 + v2;
    }
    return resp;
}

polinomio simetrico(polinomio p)
{
    int i;
    for(i=0;i<p.grau;i++) p.c[i] *= -1;
    return p;
}

polinomio produto(polinomio a, polinomio b)
{
    polinomio resp;
    int i, j;
    resp.grau = a.grau + b.grau - 1;
    for(i=0;i<resp.grau;i++) resp.c[i] = 0;
    for(i=0;i<a.grau;i++) for(j=0;j<b.grau;j++) resp.c[i+j] += a.c[i] * b.c[j];
    return resp;
}

polinomio parse_expr(char dir)
{
    int i, size, num;
    char *str, sign;
    polinomio result, aux;
    pilha p;
    p.n = -1;
    if(dir == 'L') str = el;
    else str = er;
    size = strlen(str);
    aux.grau = 0;
    for(i=0;i<size && IS_NUM(str[size - i - 1]);i++)
    {
        num = str[size - i - 1] - '0';
        if(basemin < num + 1) basemin = num + 1;
        aux.c[aux.grau++] = num;
    }
    p.pol[++p.n] = aux;
    while(i < size)
    {
        aux.grau = 0;
        sign = str[size - i++ - 1];
        while(i<size && IS_NUM(str[size - i - 1]))
        {
            num = str[size - i++ - 1] - '0';
            if(basemin < num + 1) basemin = num + 1;
            aux.c[aux.grau++] = num;
        }
        if(sign == '+') p.pol[++p.n] = aux;
        if(sign == '*') p.pol[p.n] = produto(p.pol[p.n], aux);
    }
    while(p.n != 0) p.pol[--p.n] = soma(p.pol[p.n], p.pol[p.n + 1]);
    result = p.pol[p.n];
    return result;
}

int raiz(int r, polinomio p, int indice)
{
    if(p.c[indice] % r != 0) return 0;
    if(indice == p.grau - 1)
    {
        if(p.c[indice] == 0) return 1;
        else return 0;
    }
    p.c[indice+1] += p.c[indice] / r;
    return raiz(r, p, indice+1);
}

int main()
{
    char linha[100];
    int rleft[100], rright[100];
    polinomio l, r, sub;
    int i, j, elN, erN, rlN, rrN, linhaN, grau0, tem_solucao;
    while(scanf("%s", linha) && linha[0] != '=')
    {
        linhaN = strlen(linha);
        basemin = 2;
        for(i=0;linha[i] != '=';i++) el[i] = linha[i];
        el[i++] = '\0';
        for(j=0;i+j<linhaN;j++) er[j] = linha[i+j];
        er[j] = '\0';
        erN = strlen(er);
        elN = strlen(el);
        l = parse_expr('L');
        r = parse_expr('R');
        sub = soma(l, simetrico(r));
        for(grau0=0;grau0<sub.grau;grau0++) if(sub.c[grau0] != 0) break;
        if(grau0 == sub.grau) printf("%d+\n", basemin);
        else
        {
            rrN = rlN = 0;  
            for(i=2;i*i<mod(sub.c[grau0]);i++) if(sub.c[grau0] % i == 0)
            {
                if(raiz(i, sub, grau0)) rleft[rlN++] = i;
                if(raiz(mod(sub.c[grau0]/i), sub, grau0)) rright[rrN++] = mod(sub.c[grau0] / i);
            }
            if(i*i == mod(sub.c[grau0]) && raiz(i, sub, grau0)) rleft[rlN++] = i;
            if(raiz(mod(sub.c[grau0]), sub, grau0)) rright[rrN++] = mod(sub.c[grau0]);
            tem_solucao = 0;
            stringstream ss;
            for(i=0;i<rlN;i++) if(rleft[i] >= basemin)
            {
                ss << rleft[i] << " ";
                tem_solucao = 1;
            }
            for(i=0;i<rrN;i++) if(rright[i] >= basemin)
            {
                ss << rright[i] << " ";
                tem_solucao = 1;
            }
            string s = ss.str();
            if(tem_solucao) cout << s.substr(0, s.size()-1) << endl;
            else printf("*\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int lim1, lim2, lim3;

long long int consumo(long long int c){
    if(c <= 100) return c * 2;
    if(c <= 10000) return lim1 + (c - 100) * 3;
    if(c <= 1000000) return lim2  + (c - 10000) * 5;
    else return lim3  + (c - 1000000) * 7;
}

int main(){
    long long int i, val, difconta, soma, c1, c2;
    lim1 = 200;
    lim2 = (10000 - 100) * 3 + lim1;
    lim3 = (1000000 - 10000) * 5 + lim2;
    while(scanf("%lld%lld", &val, &difconta) && val){
        if(val <= lim1) soma = val / 2;
        else if(val <= lim2) soma = 100 + (val - lim1) / 3;
        else if(val <= lim3) soma = 10000 + (val - lim2) / 5;
        else soma = 1000000 + (val - lim3) / 7;
        //todas as possibilidades.
        //c1 é o consumo menor, c2 é o consumo maior.
        //c1 > 1000000 e c2 > 1000000.
        c1 = -1;
        if(soma >= 2000000){
            c1 = (7 * soma - difconta);
            if(c1 % 14 == 0) c1 = c1 / 14;
            else c1 = -1;
            if(c1 < 1000000) c1 = -1;
        }
        //10000 < c1 < 1000000 e c2 > 1000000.
        if(soma >= 1010000 && c1 == -1){
            c1 = (lim3 - lim2 - 7000000 + 50000 - difconta + 7 * soma);
            if(c1 % 12 == 0) c1 = c1 / 12;
            else c1 = -1;
            if(c1 > 1000000 || c1 < 10000) c1 = -1;
        }
        //100 < c1 < 10000 e c2 > 1000000.
        if(soma >= 1000100 && c1 == -1){
            c1 = (lim3 - lim1 - 7000000 + 300 - difconta + 7 * soma);
            if(c1 % 10 == 0) c1 = c1 / 10;
            else c1 = -1;
            if(c1 > 10000 || c1 < 100) c1 = -1;
        }
        //c1 < 100 e c2 > 1000000.
        if(soma >= 1000000 && c1 == -1){
            c1 = (lim3 - 7000000 - difconta + 7 * soma);
            if(c1 % 9 == 0) c1 = c1 / 9;
            else c1 = -1;
            if(c1 > 100) c1 = -1;
        }
        //10000 < c1 < 1000000 e 10000 < c2 < 1000000.
        if(soma <= 2000000 && soma >= 200 && c1 == -1){
            c1 = (5 * soma - difconta);
            if(c1 % 10 == 0) c1 = c1 / 10;
            else c1 = -1;
            if(c1 > 1000000 || c1 < 10000) c1 = -1;
        }
        //100 < c1 < 10000 e 10000 < c2 < 1000000.
        if(soma <= 1010000 && soma >= 10100 && c1 == -1){
            c1 = (lim2 - lim1 - 50000 + 300 - difconta + 5 * soma);
            if(c1 % 8 == 0) c1 = c1 / 8;
            else c1 = -1;
            if(c1 > 10000 || c1 < 100) c1 = -1;
        }
        //c1 < 100 e 10000 < c2 < 1000000.
        if(soma <= 1000100 && soma >= 10000 && c1 == -1){
            c1 = (lim2 - 50000 - difconta + 5 * soma);
            if(c1 % 7 == 0) c1 = c1 / 7;
            else c1 = -1;
            if(c1 > 100) c1 = -1;
        }
        //100 < c1 < 10000 e 100 < c2 < 10000.
        if(soma <= 20000 && soma >= 200 && c1 == -1){
            c1 = (3 * soma - difconta);
            if(c1 % 6 == 0) c1 = c1 / 6;
            else c1 = -1;
            if(c1 > 10000 || c1 < 100) c1 = -1;
        }
        //c1 < 100 e 100 < c2 < 10000.
        if(soma <= 10100 && soma >= 100 && c1 == -1){
            c1 = (lim1 - 300 - difconta + 3 * soma);
            if(c1 % 5 == 0) c1 = c1 / 5;
            else c1 = -1;
            if(c1 > 100) c1 = -1;
        }
        //c1 < 100 e c2 < 100.
        if(soma <= 200 && c1 == -1){
            c1 = (2 * soma - difconta) / 4;
        }
        printf("%lld\n", consumo(c1));
    }
    return 0;
}

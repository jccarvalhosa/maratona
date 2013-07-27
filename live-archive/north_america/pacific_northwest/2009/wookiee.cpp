#include <cstdio>

char s[20][20];

int check(int x, int y, char c) {
    int i, j, cont=0;
    s[x][y]=c;
    for(i=x; s[i][y]==c; i++) cont++;
    for(i=x-1; s[i][y]==c; i--) cont++;
    if(cont>=4) return 0;
    cont=0;
    for(j=y; s[x][j]==c; j++) cont++;
    for(j=y-1; s[x][j]==c; j--) cont++;
    if(cont>=4) return 0;
    cont=0;
    for(i=x, j=y; s[i][j]==c; i++, j++) cont++;
    for(i=x-1, j=y-1; s[i][j]==c; i--, j--) cont++;
    if(cont>=4) return 0;
    cont=0;
    for(i=x, j=y; s[i][j]==c; i--, j++) cont++;
    for(i=x+1, j=y-1; s[i][j]==c; i++, j--) cont++;
    if(cont>=4) return 0;
    return 1;
}

int main() {
    int i, j;
    for(i=0;i<20;i++) for(j=0; j<20; j++) s[i][j]='.';
    while(scanf(" %c", &s[5][5]) && s[5][5]!='F') {
        for(i=0;i<4;i++) scanf(" %c", &s[5][6+i]);
        for(i=1;i<5;i++) for(j=0; j<5; j++) scanf(" %c", &s[5+i][5+j]);
        for(i=5;i<10;i++) for(j=5; j<10; j++) if(s[i][j]=='*') {
            if(check(i, j, 'X') && check(i, j, 'O')) printf("%d\n", 5*(i-5)+(j-5)+1);
            s[i][j]='*';
        }
    }
    return 0;
}

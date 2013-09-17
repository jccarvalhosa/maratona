#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int nipe(char c) {
    switch(c) {
        case 'H': return 0;
        case 'C': return 1;
        case 'D': return 2;
        case 'S': return 3;
    }
}

char cnipe(int a) {
    switch(a) {
        case 0: return 'H';
        case 1: return 'C';
        case 2: return 'D';
        case 3: return 'S';
    }
}

int number(char c) {
    if(c >= '1' && c <= '9') return c - '1';
    switch(c) {
        case 'T': return 9;
        case 'J': return 10;
        case 'Q': return 11;
        case 'K': return 12;
    }
}

int cnumber(int a) {
    if(a >= 0 && a <= 8) return a + '1';
    switch(a) {
        case 9: return 'T';
        case 10: return 'J';
        case 11: return 'Q';
        case 12: return 'K';
    }
}

int main()
{
    int N, C, i, nipf, numf, delta, ord[3];
    char c1, c2;
    vector<pair<pair<int, int>, int> > v;
    vector<int> vn;
    scanf("%d", &N);
    while(N--) {
        scanf(" %c%c ", &c1, &c2);
        nipf = nipe(c2);
        numf = number(c1);
        v.clear();
        for(i=0;i<3;i++) {
            scanf(" %c%c ", &c1, &c2);
            v.push_back(make_pair(make_pair(nipe(c2), number(c1)), i));
        }
        sort(v.begin(), v.end());
        for(i=0;i<3;i++) ord[v[i].second] = i;
        if(ord[0] == 0) {
            if(ord[1] == 1) delta = 1; 
            if(ord[1] == 2) delta = 2; 
        }
        else if(ord[0] == 1) {
            if(ord[1] == 0) delta = 3; 
            if(ord[1] == 2) delta = 4; 
        }
        else {
            if(ord[1] == 0) delta = 5;
            if(ord[1] == 1) delta = 6; 
        }
        numf = (numf + delta) % 13;
        printf("%c%c\n", cnumber(numf), cnipe(nipf));
    }
}

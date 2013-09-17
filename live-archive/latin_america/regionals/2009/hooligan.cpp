#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

struct T {
    int pts, jog, n, disp[40];
    T() {}
    void init(int i) {
        n = i;
        for(i=0;i<N;i++) disp[i] = (i == n ? 0 : M);
        pts = 0;
        jog = M*(N-1);
    }
};

bool cmp(T a, T b) { return a.pts > b.pts; }

T t[40];

void play(int a, int b, int k) {
    t[a].jog -= k;
    t[b].jog -= k;
    t[a].disp[t[b].n] -= k;
    t[b].disp[t[a].n] -= k;
}

void win(int a, int b, int k) {
    play(a, b, k);
    t[a].pts += 2*k;
}

void draw(int a, int b, int k) {
    play(a, b, k);
    t[a].pts += k;
    t[b].pts += k;
}

int main()
{
    int G, i, j, a, b;
    char c;
    while(scanf("%d%d%d", &N, &M, &G) && N) {
        for(i=0;i<N;i++) t[i].init(i);
        for(i=0;i<G;i++) {
            scanf("%d %c %d", &a, &c, &b);
            if(c == '<') win(b, a, 1);
            if(c == '>') win(a, b, 1);
            if(c == '=') draw(a, b, 1);
        }
        for(i=1;i<N;i++) win(0, i, t[0].disp[i]);
        while(N != 1) {
            sort(t, t+N, cmp);
            if(t[0].n != 0 || t[1].pts == t[0].pts) break;
            for(i=1;i<N;i++) {
                if(t[i].pts + t[i].jog*2 < t[0].pts) for(j=1;j<N;j++) if(t[i].disp[t[j].n]) win(i, j, t[i].disp[t[j].n]);
                if(!t[i].jog && t[i].pts < t[0].pts) swap(t[i], t[--N]);
            }
            for(i=1;i<N-1;i++) if(t[N-1].disp[t[i].n]) break;
            if(i != N-1) {
                if(t[N-1].pts == t[i].pts) draw(N-1, i, 1);
                else win(N-1, i, 1);
            }
        }
        if(t[0].n != 0 || t[1].pts == t[0].pts) printf("N\n");
        else printf("Y\n");
    }
    return 0;
}
